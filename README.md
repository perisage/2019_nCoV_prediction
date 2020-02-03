# 2019_nCoV_prediction

## 介绍
2019_nCoV 每日感染人数预测

## 软件依赖
用到的C++相关库: G2O GLOG(含youibot log system) GFLAGS    
用到的python功能包: math matplotlib 

## 注意事项
计算机上需要预先安装G2O 

## 安装教程
```
$ cd 2019_nCoV_prediction
$ mkdir build
$ cd build
$ cmake ..
$ make
```
## 程序运行
程序只有一个参数，即要预测的天数，通过-d命令指定，不指定时，默认为5     
### 运行示例     

采用默认的预测天数(5天)运行示例：
```
./nCov_node
```

通过-d命令指定预测天数运行示例：
```
./nCov_node -d 3
```