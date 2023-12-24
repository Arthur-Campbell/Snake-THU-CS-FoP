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
    std::vector<int> len ;      // 蛇的长度
    std::vector<P> body;        // 蛇身，负责储存蛇在所有时间的位置数据,蛇头在队尾
    P direction = P(0,-1);      // 蛇头运动的方向
    int score;     // 储存分数
    std::vector<P> apple;       // 储存苹果的位置
    double time;                // 储存时间
    std::vector<P> ops;         // 储存每次运动后的方向,作为后续记录回访的依据之一
    public:
    Snake(Config config,Map map);

    bool crashBody(P e,bool considerHead);

    void move();

    void eatApple();

    bool crashWall(P e);

    int genApplePoints();

    int crashApple(P e);

    void appleGenerate();

    //蛇的上下左右操作
    void up();

    void down();

    void left();

    void right();

    //蛇身，分数，苹果，地图打印
    void printBody();

    void printApple();

    void printScore();

    void printRedBody();

    void printTime();

    void printMap();

    //根据不同难度进行休眠
    void _sleep();

    //记录开始时间
    void start();

    //更新时间
    void updateTime();

    friend void pause(P c);
    friend void Oper(Snake & obj,Map map, char ch);
    friend void game(Config config,Map map, std::string m, std::string c);
    friend void gameOver(P mapsize, Snake obj, std::string m, std::string c);
    friend void readRecord();
    friend void writeRecord(Snake obj, std::string m, std::string c);

};

#endif // SNAKE_H