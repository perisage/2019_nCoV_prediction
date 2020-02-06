/*
 * @Author       : PeripateticWind
 * @Email        : PeripateticWind@gmail.com
 * @Company      : Xi'an Jiaotong University
 * @CreateTime   : 2020-02-03 16:29:46
 * @Description  : the declaration of clas nCoV
 * @FilePath     : /2019_nCoV_prediction/2019_nCoV_prediction/include/nCoV.h
 * @LastEditors  : PeripateticWind
 * @LastEditTime : 2020-02-05 22:09:17
 * @youwant      : add what you want
 * @Copyright (c) 2020, PeripateticWind. All rights reserved.
 */

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

class nCoV
{
private:
    int                 _dataSize;     // 数据量，每天1条数据，即为天数
    int                 _predictDays;  // 要预测的天数
    std::ifstream       _dataFile;     // 数据文件
    std::vector<double> _xData;        // 优化模型的自变量，为每日日期
    std::vector<double> _yData;        // 优化模型的因变量，为每日累计感染人数

    double          _parameter[3];        // 待优化的SIR模型参数的初值
    Eigen::Vector3d _parameterEstimated;  // 优化后的SIR模型参数值

    void optimize();  // 模型优化
    void predict();   // 模型预测
public:
    nCoV(int predictDays);  // 构造函数
};

#endif  // !__NCOV_H__
