/**
 * @file curve_fitting_vertex.h
 * @author PeripateticWind (zhangzhihong@stu.xjtu.edu.cn)
 * @brief The G2O model's vertex implementation file
 * @version 1.0.0
 * @date 2020-02-10 22:43:51
 * @lasteditor PeripateticWind
 * @lastedittime 2020-02-10 22:43:51
 * @email zhangzhihong@stu.xjtu.edu.cn
 * @company Xi'an Jiaotong University
 * @copyright Copyright (c) 2020 PeripateticWind.   All rights reserved.
 * @license Licensed under the MIT License.
 * @par Changelog
 * <table>
 * <caption>Change Log</caption>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2020-02-10 22:43:51 <td>1.0.0     <td>PeripateticWind     <td>change log
 * </table>
 *
 **/

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
