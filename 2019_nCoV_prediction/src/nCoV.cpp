/*
 * @Author       : PeripateticWind
 * @Email        : PeripateticWind@gmail.com
 * @Company      : Xi'an Jiaotong University
 * @CreateTime   : 2020-02-03 16:29:46
 * @Description  : the implementation of clas nCoV
 * @FilePath     : /2019_nCoV_prediction/2019_nCoV_prediction/src/nCoV.cpp
 * @LastEditors  : PeripateticWind
 * @LastEditTime : 2020-02-04 22:06:30
 * @youwant      : add what you want
 * @Copyright (c) 2020, PeripateticWind. All rights reserved.
 */
#include "nCoV.h"

/**
 * @brief Construct a new nCoV::nCoV object
 * 
 */
nCoV::nCoV()
    : _dataFile("../data/data.txt")          // 数据文件
      ,                                      // 待优化的变量，依次为SIR模型中的 S0(易感人群), I0(感染人群), γβ(传染期接触数)
      _parameter{100000.0, 58.0, 0.02123106} // 初始参数值 I0从2020.01.17开始算起，一方面从17日开始有明显增长，另一方面缺少16日的数据
      ,
      _parameterEstimated{0.0, 0.0, 0.0} // 优化后的参数值初值
{
    if (!_dataFile.is_open())
    {
        LOG_FATAL << "open data file failed and program exit!";
    }
    LOG_INFO << "load data file successfully!";
    // 填充数据
    double tempData;
    while (_dataFile >> tempData)
    {
        _yData.push_back(tempData);
    }
    _dataFile.close();
    for (size_t i = 0; i < _yData.size(); ++i) // 从2020.1.17日开始计算到当前日期(以天为单位)
    {
        _xData.push_back(i);
    }
    _dataSize = _yData.size();
    // verbose
    DLOG_INFO << "_x:";
    std::for_each(_xData.begin(), _xData.end(), [&](const double d) { DLOG_INFO << d << " "; });
    DLOG_INFO << "_y:";
    std::for_each(_yData.begin(), _yData.end(), [&](const double d) { DLOG_INFO << d << " "; });
}

//! 模型优化
/*!
 * @brief G2O图模型优化
 **/
void nCoV::optimize()
{
    // solver
    // 构建图优化，先设定g2o
    // 矩阵块：每个误差项优化变量的维度为3，误差值维度为1
    typedef g2o::BlockSolver<g2o::BlockSolverTraits<3, 1>> Block; // 待优化变量为一个三维向量 //block solver
    // 线性方程求解器：稠密的增量方程
    std::unique_ptr<Block::LinearSolverType> linearSolver(new g2o::LinearSolverDense<Block::PoseMatrixType>()); // 线性求解器
    std::unique_ptr<Block> solverPtr(new Block(std::move(linearSolver)));
    //梯度下降方法，GN, LM, DogLeg 三种优化方法，选择LM优化
    g2o::OptimizationAlgorithm *solver(new g2o::OptimizationAlgorithmLevenberg(std::move(solverPtr))); // 配置求解器 LM优化
    // g2o::OptimizationAlgorithm *solver(new g2o::OptimizationAlgorithmGaussNewton(std::move(solver_ptr))); // 配置求解器 GN优化
    // g2o::OptimizationAlgorithm *solver(new g2o::OptimizationAlgorithmDogleg(std::move(solver_ptr)));      // 配置求解器 DogLeg优化

    g2o::SparseOptimizer optimizer; // 图模型
    optimizer.setAlgorithm(solver); //设置求解器
    optimizer.setVerbose(false);    //关闭输出调试

    // 图模型中有一个节点，边的个数为从2020.01.17到当前天的天数
    // 向图中添加顶点
    CurveFittingVertex *vertex = new CurveFittingVertex();
    vertex->setEstimate(Eigen::Vector3d(_parameter[0], _parameter[1], _parameter[2])); // 设置该顶点的初始观测量
    vertex->setId(0);                                                                  // 设置该顶点的ID
    optimizer.addVertex(vertex);                                                       // 将该顶点添加到图模型中

    // 向图中添加边
    for (size_t i = 0; i < _yData.size(); i++)
    {
        CurveFittingEdge *edge = new CurveFittingEdge(_xData[i]);      // 构造边
        edge->setId(i);                                                // 设置该边的ID
        edge->setVertex(0, vertex);                                    // 设置连接的顶点
        edge->setMeasurement(_yData[i]);                               // 设置该边的观测值
        edge->setInformation(Eigen::Matrix<double, 1, 1>::Identity()); // 信息矩阵：协方差矩阵之逆 Gussian分布的协方差的逆
        optimizer.addEdge(edge);                                       // 将该边添加到图模型中
    }

    // 执行优化
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    optimizer.initializeOptimization();
    optimizer.optimize(100); // 参数为迭代次数
    std::chrono::duration<double> timeUsed = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - t1);
    LOG_INFO << "solve time cost:" << timeUsed.count() << " seconds.";

    // 输出优化值
    _parameterEstimated = vertex->estimate();
    LOG_INFO << "estimated matrix: " << _parameterEstimated.transpose();
    LOG_INFO << "estimated SIR model: y=" << _parameterEstimated[0] << "*" << _parameterEstimated[1] << "/(" << _parameterEstimated[1] << "+(" << _parameterEstimated[0] << "-" << _parameterEstimated[1] << ")e^(-" << _parameterEstimated[2] << "x))";
    LOG_WARNING << "The 2019_nCoV SIR model S0 is " << static_cast<int>(_parameterEstimated[0]);
    LOG_WARNING << "The SARS SIR model S0 is " << 5237.0;
    LOG_WARNING << "2019_nCoV is " << LOG_RED << _parameterEstimated[0] / 5237.0 << LOG_YELLOW << " times of the SARS!";

    std::ofstream parameterFile("../data/parameter.txt"); // 模型参数文件
    if (!parameterFile.is_open())
    {
        LOG_FATAL << "write parameter to file failed and program exit!";
    }
    parameterFile << _parameterEstimated[0] << " " << _parameterEstimated[1] << " " << _parameterEstimated[2];
    parameterFile.close();
    LOG_INFO << "write parameter to file successfully!";
}

//! 感染人数预测
/*!
 * @brief 根据优化的图模型，预测指定天数每天的感染人数
 * @param input predictDays 待预测的天数
 **/
void nCoV::predict(int predictDays)
{
    time_t currentTime = time(0);     // 获取当前日期
    std::stringstream strTime;        // 用以将日期转为字符串
    LOG_INFO << "  date\t\tinfected"; // 表格标题
    // 输出已有数据
    currentTime -= 86400 * _dataSize; // 日期调整到第一天
    LOG_INFO << "-----optimization-----";
    for (size_t i = 0; i < _dataSize; ++i)
    {
        currentTime += 86400;                                             // 日期增加一天
        strTime.str("");                                                  // 清空stringstream
        strTime << std::put_time(std::localtime(&currentTime), "%Y%m%d"); // 设置日期格式
        LOG_INFO << strTime.str() << "\t" << _yData[i];
    }
    LOG_INFO << "-----prediction-----";
    currentTime = time(0); // 重置为当前日期
    for (size_t i = 0; i < predictDays; ++i)
    {
        currentTime += 86400;                                             // 日期增加一天
        strTime.str("");                                                  // 清空stringstream
        strTime << std::put_time(std::localtime(&currentTime), "%Y%m%d"); // 设置日期格式
        int infected = static_cast<int>(_parameterEstimated[0] * _parameterEstimated[1] / (_parameterEstimated[1] + (_parameterEstimated[0] - _parameterEstimated[1]) * exp(-_parameterEstimated[2] * (_dataSize + i))) + 0.5);
        LOG_INFO << strTime.str() << "\t" << infected;
    }
}
