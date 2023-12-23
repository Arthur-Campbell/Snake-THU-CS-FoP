#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "P.h"
#include "map.h"
#include "config.h"
#include <string>

/// @brief 本文件中所有的mapsize仅用于确定文本内容输出位置

/// @brief 根据配置和地图唯一地创建游戏， m 和 c是用来储存map和config名字的变量
void game(Config config,Map map, std::string m, std::string c);

/// @brief 游戏结束，决定是否要保存记录， Snake用来记录
void gameOver(P mapsize, Snake obj, std::string m, std::string c);

/// @brief 读入操作，根据读入字符进行相应操作
void Oper(Snake &obj, Map map, char ch);

/// @brief暂停，涉及到中途退出，gameover的修改
void pause(P mapsize);

void printConfAndMapName(P mapsize, std::string m, std::string c);

#endif  // GAME_H
