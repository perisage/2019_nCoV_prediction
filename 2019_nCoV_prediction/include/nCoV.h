/**
 * @file nCoV.h
 * @author PeripateticWind (zhangzhihong@stu.xjtu.edu.cn)
 * @brief  the nCoV class declaration file
 * @version 1.0.0
 * @date 2020-02-10 22:43:22
 * @lasteditor PeripateticWind
 * @lastedittime 2020-02-10 22:43:22
 * @email zhangzhihong@stu.xjtu.edu.cn
 * @company Xi'an Jiaotong University
 * @copyright Copyright (c) 2020 PeripateticWind.   All rights reserved.
 * @license Licensed under the MIT License.
 * @par Changelog
 * <table>
 * <caption>Change Log</caption>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2020-02-10 22:43:22 <td>1.0.0     <td>PeripateticWind     <td>change log
 * </table>
 *
 **/

// #pragma once
#ifndef __NCOV_H__
#define __NCOV_H__

// STL
#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>

// Eigen
#include <Eigen/Core>

// G2O
#include <g2o/core/block_solver.h>
#include <g2o/core/optimization_algorithm_dogleg.h>
#include <g2o/core/optimization_algorithm_gauss_newton.h>
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/solvers/dense/linear_solver_dense.h>

// GLOG
#include <glog/log.h>

// USER
#include "curve_fitting_edge.h"
#include "curve_fitting_vertex.h"

/**
 * @brief
 *
 */
//!  A test class.
/*!
  A more elaborate class description.
*/
class nCoV
{
private:
    //! 数据量，每天1条数据，即为天数
    int _dataSize;

    //! 要预测的天数
    int _predictDays;

    //! 数据文件
    std::ifstream _dataFile;

    //! 优化模型的自变量，为每日日期
    std::vector<double> _xData;

    //! 优化模型的因变量，为每日累计感染人数
    std::vector<double> _yData;

    double          _parameter[3];        // 待优化的SIR模型参数的初值
    Eigen::Vector3d _parameterEstimated;  // 优化后的SIR模型参数值

    void optimize();  // 模型优化
    void predict();   // 模型预测
public:
    nCoV(int predictDays);  // 构造函数
};

#endif  // !__NCOV_H__
