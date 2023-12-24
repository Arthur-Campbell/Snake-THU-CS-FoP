#include <vector>
#include <string>
#include "P.h"

#ifndef MAP_H
#define MAP_H

/// @brief Map类的定义,用于储存地图信息,地图的左上角坐标为(0,0)，右下角坐标为(map.x,map.y)
struct Map {
    P mapsize = P(15,15); // 地图大小
    std::vector<P> obstacle; // 障碍物位置，包括墙壁
    int left;   // 左墙壁
    int right;  // 右墙壁
    int up;     // 上墙壁
    int down;   // 下墙壁
    int obstacleNum; // 障碍物数量
    Map(){ // 默认地图
        mapsize = P(15,15);
        obstacle.clear();
        left = 1;
        right = 1;
        up = 1;
        down = 1;
        obstacleNum = 0;
    }

    /// @brief 根据墙壁虚实生成地图
    void buildMap();

    /// @brief 打印地图
    void printMap();
};

/// @brief 写入地图文件
void writeMap();

/// @brief 读取地图文件
Map readMap(std::string &s);
#endif