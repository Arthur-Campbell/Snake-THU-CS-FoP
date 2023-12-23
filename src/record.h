#ifndef RECORD_H
#define RECORD_H	


#include "snake.h"
#include <string>

/// @brief 写入记录，m,c用来储存地图名和配置名，snake用来写入config，map和每帧蛇的运行方向
void writeRecord(Snake obj, std::string m, std::string c);

/// @brief 打印地图名和配置名
void recordPrintConfAndMapName(P mapsize, std::string m, std::string c);

/// @brief 读入Snake，并进行现场演示
void readRecord();

#endif // !RECORD_H