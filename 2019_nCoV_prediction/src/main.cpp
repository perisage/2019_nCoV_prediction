#include "nCoV.h"

/**
 * 本程序用来预测每日感染人数
 * 数据来源：http://m.medsci.cn/wh.asp
 **/

int main(int argc, char **argv)
{

    Glogger logger("2019_nCoV_prediction"); // 初始化日志系统

    nCoV ncov;
    ncov.optimize(); // 模型优化
    ncov.predict(5); // 感染人数预测
    return 0;
}
