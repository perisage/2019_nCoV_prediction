/*
 * @Author       : PeripateticWind
 * @Email        : PeripateticWind@gmail.com
 * @Company      : Xi'an Jiaotong University
 * @CreateTime   : 2020-02-03 16:29:46
 * @Description  : main Node for nCoV prediction
 * @FilePath     : /2019_nCoV_prediction/2019_nCoV_prediction/src/main.cpp
 * @LastEditors  : PeripateticWind
 * @LastEditTime : 2020-02-04 21:54:36
 * @youwant      : add what you want
 * @Copyright (c) 2020, PeripateticWind. All rights reserved.
 */

// GFLAGS
#include <gflags/gflags.h>
// USER
#include "nCoV.h"

/**
 * 本程序用来预测每日感染人数
 * 数据来源：http://m.medsci.cn/wh.asp
 **/

DEFINE_int32(d, 5, "the days to predict"); // 要预测的天数

int main(int argc, char **argv)
{
    Glogger logger("2019_nCoV_prediction"); // 初始化日志系统
    // 解析gflags 参数
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    LOG_HINT(LOG_GREEN) << "get predictDays: " << FLAGS_d;

    nCoV ncov;
    ncov.optimize();       // 模型优化
    ncov.predict(FLAGS_d); // 感染人数预测

    // 调用python脚本绘制曲线
    const char *cmd = "python ../scripts/plot_sir.py";
    return system(cmd);
}
