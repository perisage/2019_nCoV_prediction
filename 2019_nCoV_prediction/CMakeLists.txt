#####
 # @Author       : PeripateticWind
 # @Email        : zhangzhihong@stu.xjtu.edu.cn
 # @Company      : Xi'an Jiaotong University
 # @CreateTime   : 2020-02-03 16:29:46
 # @Description  : 
 # @FilePath     : /2019_nCoV_prediction/2019_nCoV_prediction/CMakeLists.txt
 # @LastEditors: PeripateticWind
 # @LastEditTime: 2020-02-09 17:06:23
 # @youwant      : add what you want
 # @Copyright (c) 2020, PeripateticWind. All rights reserved.
#####
cmake_minimum_required(VERSION 3.5)
project(2019_nCoV_prediction)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

# 添加cmake模块以使用g2o库
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )

find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)
find_package(G2O REQUIRED)

include_directories(
    ${EIGEN3_INCLUDE_DIR}
    ${G2O_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/include
    )   

set(SRC_LIST src/main.cpp)

add_library(nCoV
            src/nCoV.cpp)

add_executable(nCoV_node ${SRC_LIST})
target_link_libraries(nCoV_node 
    nCoV
    ${CERES_LIBRARIES} 
    g2o_core
    g2o_stuff
    )


# autogen docs
include(docs/build_doxygen.cmake)
autogen_docs()