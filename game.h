#include "snake.h"
#include "P.h"
#include "map.h"
#include "config.h"

#ifndef GAME_H
#define GAME_H

void game(Config config,Map map);

void gameOver(P mapsize);

void Oper(Snake &obj, Map map);

void pause(P mapsize);

#endif  // GAME_H