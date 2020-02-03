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
    virtual void setToOriginImpl() override // 设置顶点的初始值
    {
        _estimate << 0, 0, 0; // estimate即为需要更新的顶点数据(此处为一个3维向量)
    }

    virtual void oplusImpl(const double *update) override // 设置顶点的更新规则 update为更新量
    {
        _estimate += Eigen::Vector3d(update);
    }
    // 存盘和读盘:留空
    virtual bool read(std::istream &in) override {}
    virtual bool write(std::ostream &out) const override {}
};
