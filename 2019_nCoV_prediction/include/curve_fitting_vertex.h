/*
 * @Author       : PeripateticWind
 * @Email        : PeripateticWind@gmail.com
 * @Company      : Xi'an Jiaotong University
 * @CreateTime   : 2020-02-03 16:29:46
 * @Description  : G2O vertex definition
 * @FilePath     : /2019_nCoV_prediction/2019_nCoV_prediction/include/curve_fitting_vertex.h
 * @LastEditors  : PeripateticWind
 * @LastEditTime : 2020-02-04 22:06:03
 * @youwant      : add what you want
 * @Copyright (c) 2020, PeripateticWind. All rights reserved.
 */

#pragma once

// STL
#include <iostream>

// Eigen
#include <Eigen/Core>

// G2O
#include <g2o/core/base_vertex.h>

class CurveFittingVertex : public g2o::BaseVertex<3, Eigen::Vector3d>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    /**
     * @brief Set the To Origin Impl object
     *
     */
    virtual void setToOriginImpl() override  // 设置顶点的初始值
    {
        _estimate << 0, 0, 0;  // estimate即为需要更新的顶点数据(此处为一个3维向量)
    }

    /**
     * @brief 设置顶点的更新规则 update为更新量
     *
     * @param update
     */
    virtual void oplusImpl(const double* update) override { _estimate += Eigen::Vector3d(update); }
    // 存盘和读盘:留空
    virtual bool read(std::istream& in) override {}
    virtual bool write(std::ostream& out) const override {}
};
