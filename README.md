# Relocation

## 介绍
激光导航重定位

## 软件架构
软件架构说明
1. 节点订阅服务 /relocalization_local,当客户端调用用该服务，并传入参数为："data: true" 时，运行重定位程序。("data: false"时，不运行任何程序)
2. 重定位的结果带有协方差矩阵。

## 注意事项
1.  在进行重定位时，不要移动机器人,保持机器人绝对静止；   
2.  重定位时，地图环境与实际环境不能有太大差异(最好保持基本一致)，尤其是不能有较多地图中没有的障碍物，如果差异太大，会导致重定位失败；     
3.  给定的机器人位置与真实位置不能差太远(最大2m左右)，角度亦不能相差太远(±30°)，方可重定位成功；   
4.  如果重定位位置有偏差，可尝试多次调用重定位服务；     
5.  目前只支持调用局部重定位，全局重定位功能暂时未实现，请勿使用。    


## 安装教程
1.  安装依赖：ROS-Kinetic pcl(version >= 1.7) Eigen3
2.  编译功能包 catkin_make  --pkg youibot_relocalization

## 使用说明 重定位流程

### 准备
1.  在youibot_relocalization.launch中正确设置相应的参数。详细如下：
    1.1. 参数1： map_frame_id，全局坐标系名称，默认为“map”；    
    1.2. 参数2： base_frame_id，机器人坐标系名称，默认为“base_link”；    
    1.3. 参数3： laser_frame_id，激光雷达所在坐标系名称，默认为“base_laser_link”；    
    1.4. 参数4： laserscan_topic，经过laser_processor包处理的激光雷达数据的话题名称，默认为“scan_localization”；    
    1.5. 参数5： angle_increment，ICP进行360度配准的角度增量(单位为°)，默认为“30”；    
    1.6. 参数6： region_pose_topic，暂未用到。    
2.  运行节点:roslaunch youibot_relocalization youibot_relocalization.launch   

### 局部重定位
1.  调用服务 rosservice　call　/relocalization_local　"data: true"　(注意，只有当data的值设置为true时，才执行重定位)
2.  等待重定位结果   
    2.1  重定位成功时返回结果：  
    success: True
    message: "relocalization success!"   
    2.2  重定位失败时返回结果：  
    success: False
    message: "relocalization failed!"  
    2.3  参数错误时返回结果：  
    success: False
    message: "Parameter data must be [true]!" 

### 全局重定位(只留了接口，目前功能没有实现，暂时不要用)
1.  调用服务 rosservice　call　/relocalization_global "data: true"　(注意，只有当data的值设置为true时，才执行重定位)
2.  等待重定位结果   
    2.1  重定位成功时返回结果：  
    success: True
    message: "relocalization success!"   
    2.2  重定位失败时返回结果：  
    success: False
    message: "relocalization failed!"  
    2.3  参数错误时返回结果：  
    success: False
    message: "Parameter data must be [true]!"     




