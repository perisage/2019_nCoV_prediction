/**
 * @file main.cpp
 * @author PeripateticWind (zhangzhihong@stu.xjtu.edu.cn)
 * @brief  the 2019_nCoV prediction program main node
 * @version 1.0.0
 * @date 2020-02-10 22:42:35
 * @lasteditor PeripateticWind
 * @lastedittime 2020-02-10 22:42:35
 * @email zhangzhihong@stu.xjtu.edu.cn
 * @company Xi'an Jiaotong University
 * @copyright Copyright (c) 2020 PeripateticWind.   All rights reserved.
 * @license Licensed under the MIT License.
 * @par Changelog
 * <table>
 * <caption>Change Log</caption>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2020-02-10 22:42:35 <td>1.0.0     <td>PeripateticWind     <td>change log
 * </table>
 *
 **/

// GOOGLE GFLAGS
#include <gflags/gflags.h>

// USER
#include "nCoV.h"

/**
 * 本程序用来预测每日感染人数
 * 数据来源：http://m.medsci.cn/wh.asp
 **/

DEFINE_int32(d, 5, "the days to predict");  // 要预测的天数

int main(int argc, char** argv)
{
    Glogger logger("2019_nCoV_prediction");  // 初始化日志系统
    // 解析gflags  参数
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    LOG_HINT(LOG_GREEN) << "get predictDays: " << FLAGS_d;

    nCoV ncov(FLAGS_d);  // 模型优化与预测

    // TODO: 此处应该在C++中直接将数据传递给脚本，而不是以system command的形式去调用
    // 调用python脚本绘制曲线
    const char* cmd = "python ../scripts/plot_sir.py";
    return system(cmd);
}
