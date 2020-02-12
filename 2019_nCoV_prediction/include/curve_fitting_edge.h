/**
 * @file curve_fitting_edge.h
 * @author PeripateticWind (zhangzhihong@stu.xjtu.edu.cn)
 * @brief The G2O model's edge implementation file
 * @version 1.0.0
 * @date 2020-02-10 22:44:06
 * @lasteditor PeripateticWind
 * @lastedittime 2020-02-10 22:44:06
 * @email zhangzhihong@stu.xjtu.edu.cn
 * @company Xi'an Jiaotong University
 * @copyright Copyright (c) 2020 PeripateticWind.   All rights reserved.
 * @license Licensed under the MIT License.
 * @par Changelog
 * <table>
 * <caption>Change Log</caption>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2020-02-10 22:44:06 <td>1.0.0     <td>PeripateticWind     <td>change log
 * </table>
 *
 **/

#ifndef __CURVE_FITTING_EDGE_H__
#define __CURVE_FITTING_EDGE_H__

// STL
#include <iostream>

// Eigen
#include <Eigen/Core>

// G2O
#include <g2o/core/base_unary_edge.h>

// USER
#include "curve_fitting_vertex.h"

//! CurveFittingEdge g2o图优化模型的边类
/**
 * @brief g2o图优化模型的边类，定义残差计算规则和模型的自变量
 *
 **/
class CurveFittingEdge : public g2o::BaseUnaryEdge<1, double, CurveFittingVertex>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    //! G2O边模型构造函数
    /**
     * @brief Construct a new Curve Fitting Edge object
     *
     * @param[in] x 模型自变量x
     */
    CurveFittingEdge(double x)
        : BaseUnaryEdge()
        , _x(x)
    {
    }

    /**
     * @brief 计算曲线模型误差
     *
     */
    virtual void computeError() override  // 本函数提供误差计算模型
    {
        const CurveFittingVertex* vertex           = static_cast<const CurveFittingVertex*>(_vertices[0]);  // 获取顶点
        const Eigen::Vector3d     vertexEstimation = vertex->estimate();                                    // 获取估计值

        _error(0, 0) = _measurement - vertexEstimation(0, 0) * vertexEstimation(1, 0) / (vertexEstimation(1, 0) + (vertexEstimation(0, 0) - vertexEstimation(1, 0)) * std::exp(-vertexEstimation(2, 0) * _x));  // 计算误差值 _measurement为观测值,
    }

    //! 读盘,留空
    virtual bool read(std::istream& in) override {}
    //! 存盘,留空
    virtual bool write(std::ostream& out) const override {}

private:
    double _x;  ///< x的值 y的值为_measurement
};

#endif  // !__CURVE_FITTING_EDGE_H__
