#ifndef RECORD_H
#define RECORD_H	


#include "snake.h"
#include <string>

/// @brief 写入记录， 通过储存Snake的config和map，以及每次行进的方向来储存一局游戏 ，c、m用来打印配置名和地图名
void writeRecord(Snake obj, std::string m, std::string c);

/// @brief 打印配置名和地图名
void recordPrintConfAndMapName(P mapsize, std::string m, std::string c);

/// @brief 从文件读入一局游戏，并在函数中进行回放演示
void readRecord();

#endif // !RECORD_H
