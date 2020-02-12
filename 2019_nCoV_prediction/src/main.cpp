/**
 * @file main.cpp
 * @mainpage The 2019-nCoV Prediction Application
 * @author PeripateticWind (zhangzhihong@stu.xjtu.edu.cn)
 * @brief the 2019_nCoV prediction application main node
 * @version 1.0.0
 * @date 2020-02-10 22:42:35
 * @lasteditor PeripateticWind
 * @lastedittime 2020-02-10 22:42:35
 * @email zhangzhihong@stu.xjtu.edu.cn
 * @company Xi'an Jiaotong University
 * @todo
 * -# to add the details of the change log
 * @bug
 * -# the date will be wrong if no data of current day
 * @section introduction_ection Introduction
 * 2019_nCoV 每日感染人数预测程序
 * @section dependencies_section Dependencies
 * -# 用到的C++相关库: G2O GLOG(含youibot log system) GFLAGS
 * -# 用到的python功能包: math matplotlib
 * @section note_section Note Items
 * -# 计算机上需要预先安装G2O。
 * -# 日志系统使用的是公司的日志系统，暂不开源，请谅解。如果要在自己的计算机上运行，可将代码中的日志替换为C++标准输出`std::cout<<`,并取消main中Glogger对象的定义即可。
 * @section install_section Installation
 * Just as the follows
 * @subsection step1 Step 1: install g2o and youibot log system from github
 * @subsection step2 Step 2: install math and matplotlib packages for python
 * @subsection step3 Step 3: install the application
 * @code
 * $ cd 2019_nCoV_prediction
 * $ mkdir build
 * $ cd build
 * $ cmake ..
 * $ make
 * @endcode
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
