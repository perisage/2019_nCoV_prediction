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

add_library(nCov
            src/nCoV.cpp)

add_executable(nCov_node ${SRC_LIST})
target_link_libraries(nCov_node 
    nCov
    ${CERES_LIBRARIES} 
    g2o_core
    g2o_stuff
    )