#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "P.h"
#include "map.h"
#include "config.h"
#include <string>


void game(Config config,Map map, std::string m, std::string c);

void gameOver(P mapsize, Snake obj, std::string m, std::string c);

void Oper(Snake &obj, Map map, char ch);

void pause(P mapsize);

void printConfAndMapName(P mapsize, std::string m, std::string c);

#endif  // GAME_H