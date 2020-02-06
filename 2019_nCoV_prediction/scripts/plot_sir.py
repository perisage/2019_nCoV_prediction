#!/usr/bin/env python
# coding=utf-8
'''
@Author       : PeripateticWind
@Email        : PeripateticWind@gmail.com
@Company      : Xi'an Jiaotong University
@CreateTime   : 2020-02-03 21:03:40
@Description  : scripts to draw SIR model
@FilePath     : /2019_nCoV_prediction/2019_nCoV_prediction/scripts/plot_sir.py
@LastEditors  : PeripateticWind
@LastEditTime : 2020-02-06 09:21:26
@youwant      : add what you want
@Copyright (c) 2020, PeripateticWind. All rights reserved.
'''

import math
import matplotlib.pyplot as plt
import os

with open('../data/parameter.txt', 'r') as f:
    my_data = f.readlines()  # txt中所有字符串读入data，得到的是一个list
    for line in my_data:  # 对list中的数据做分隔和类型转换
        line_data = line.split()
        parameter = map(float, line_data)  # 转化为浮点数

x = range(0, 50, 1)
y = []
for i, iter in enumerate(x):
    y.append(int(parameter[0] * parameter[1] / (parameter[1] +
                                                (parameter[0] - parameter[1]) * math.exp(-parameter[2] * iter)) + 0.5))

plt.plot(x, y,  color='r', markerfacecolor='blue', marker='o')
for a, b in zip(x, y):
    if a <= 14:
        plt.text(a, b, ("01_"+str(a+17), b),
                 ha='center', va='bottom', fontsize=10)
    else:  # 此处考虑将预测的部分用红色显示
        plt.text(a, b, ("02_"+str(a-14), b),
                 ha='center', va='bottom', fontsize=10)

plt.legend()
plt.show()
