#include <vector>
#include <cstdlib>
#include "P.h"
#include "config.h"
#include <chrono>
#include "map.h"
/// @brief Snake类的定义
/// @details 由config和map唯一决定

#ifndef SNAKE_H
#define SNAKE_H

class Snake;

class Snake
{
    private:
    std::chrono::system_clock::time_point startTime;
    Map map;
    Config config;
    std::vector<int> len ;   // 蛇的长度
    std::vector<P> body; // 蛇身，负责储存蛇在所有时间的位置数据,蛇头在队尾
    P direction = P(0,-1);    // 蛇头运动的方向
    std::vector<int> score; // 储存分数
    std::vector<P> apple; // 储存苹果的位置
    std::vector<double> time; // 储存时间

    public:
    Snake(Config config,Map map);

    bool crashBody(P e,bool considerHead);

    void move();

    void eatApple();

    bool crashWall(P e);

    int genApplePoints();

    int crashApple(P e);

    void appleGenerate();

    void up();

    void down();

    void left();

    void right();

    void printBody();

    void printApple();

    void printScore();

    void printMap();

    void printRedBody();

    void _sleep();

    void printTime();

    void start();

    void updateTime();

    friend void pause(P c);
    friend void Oper(Config config,Map map);
    friend void game(Config config,Map map);
    friend void gameOver(P mapsize , bool &gameover);

};

#endif // SNAKE_H