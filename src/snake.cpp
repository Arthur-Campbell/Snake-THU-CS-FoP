/// @brief Snake类的实现
#include "snake.h"
#include <ctime>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <iomanip>
#include "print.h"
#include <cstdlib>

Snake::Snake(Config config,Map map):config(config),map(map){
        config.init();
        direction = P(0,-1);
        body.push_back(P(map.mapsize.x / 2, map.mapsize.y / 2 +3));
        body.push_back(P(map.mapsize.x / 2, map.mapsize.y / 2 +2));
        body.push_back(P(map.mapsize.x / 2, map.mapsize.y / 2 + 1));
        body.push_back(P(map.mapsize.x / 2, map.mapsize.y / 2));// 初始长度为4
        len.push_back(4);
        score.push_back(0);
        start();
        updateTime();
}

bool Snake::crashBody(P e , bool considerHead){
    size_t pointer = body.size() - 1 - !considerHead;
    int temp =  len.back() - !considerHead;
        for (int i = 0; i < temp; i++)
        {
            if (body[pointer - i] == e)
            {
                return true;
            }
        }
        return false;
}

void Snake::move(){
        P head = body.back();
        int x = head.x + direction.x;
        int y = head.y + direction.y;
        x = x + map.mapsize.x+1;
        y = y + map.mapsize.y + 1;
        x %= (map.mapsize.x + 1);
        y %= (map.mapsize.y + 1);
        P newhead = P(x, y);
        body.push_back(newhead);
        ops.push_back(direction);
}

void Snake::eatApple(){
    int temp = score.back()+crashApple(body.back());
    len.push_back(temp+4);
    score.push_back(temp);
}

bool Snake::crashWall(P e){
        for(int i=0;i<map.obstacle.size();i++){
            if (e==map.obstacle[i]) return true;
            }
        return false;
}

int Snake::genApplePoints(){
        double x = ((double) rand() / RAND_MAX );
        if(x <config.one){
            return 1;//一分
        }
        else if (x<config.one+config.two){
            return 2;//两分
        }
        else{
            return 3;//三分
        } 
}

int Snake::crashApple(P e){
        for(int i =0 ;i<apple.size();i++){
            if(apple[i] == e){
                int temp = apple[i].points;
                apple.erase(apple.begin()+i);
                return temp;
            }
        }
        return 0;
}

void Snake::appleGenerate(){
    while(apple.size() < config.applenum){
        P newapple = P(rand()%map.mapsize.x, rand()%map.mapsize.y, genApplePoints());
        while(crashBody(newapple, 1)||crashWall(newapple)||crashApple(newapple)){
            newapple = P(rand()%map.mapsize.x, rand()%map.mapsize.y, genApplePoints());
        }
        apple.push_back(newapple);
    }
}

/// @brief 蛇的移动
void Snake::up(){
    if (direction != P(0, 1)) 
        direction = P(0,-1);
}

void Snake::down(){
    if(direction != P(0,-1))
    direction = P(0,1);
}

void Snake::left(){
    if(direction != P(1,0))
    direction = P(-1,0);
}

void Snake::right(){
    if(direction != P(-1,0))
        direction = P(1,0);
}

/// @brief 打印蛇身，蛇头为#，蛇身为*，颜色分别为白色和青色
void Snake::printBody()
{   
    size_t temp = body.size()-1;
    int length = this->len.back();
    for(int i=0;i<length;i++){
        gotoxy(body[temp-i].x,body[temp-i].y);
        std::cout <<"\033[46m"<< "*";
    }
    std::cout <<"\033[0m";
    std::cout <<"\033[47m";
    gotoxy(body[temp].x,body[temp].y);
    std::cout << "#";
    std::cout <<"\033[0m";
}

/// @brief 打印蛇身，蛇头为#，蛇身为*，颜色为红色
void Snake::printRedBody()
{   
    size_t temp = body.size()-1;
    int length = this->len.back();
    for(int i=0;i<length;i++){
        gotoxy(body[temp-i].x,body[temp-i].y);
        std::cout <<"\033[41m"<< "*";
    }
    gotoxy(body[temp].x,body[temp].y);
    std::cout << "#";
    std::cout <<"\033[0m";
}

/// @brief 打印地图
void Snake::printMap() {
    for (int i = 0; i < map.obstacle.size(); i++)
    {
        gotoxy(map.obstacle[i].x, map.obstacle[i].y);
        std::cout << "+";
    }
}

/// @brief 打印苹果，分数为1的苹果为绿色，分数为2的苹果为黄色，分数为3的苹果为红色
void Snake::printApple()
{
    for(int i = 0; i < apple.size(); i++)
    {
        gotoxy(apple[i].x, apple[i].y);
        switch(apple[i].points){
            case 1:
                std::cout <<"\033[42m";
                break;
            case 2:
                std::cout <<"\033[43m";
                break;
            case 3:
                std::cout <<"\033[41m";
                break;
            default:
                break;
        }
        std::cout<<"@"<<"\033[0m";
    }
}

/// @brief 打印得分，在地图的下方
void Snake::printScore(){
    gotoxy(0, map.mapsize.y + 1);
    std::cout << "Score: " << score.back();
}

/// @brief 根据蛇的速度进行延时
void Snake::_sleep(){
        Sleep(1000/config.difficulty);
};

/// @brief 打印时间，在地图的最下方
void Snake::printTime(){
    gotoxy(0, map.mapsize.y + 3);
    std::cout << "Game Time (S): " << time;
}

/// @brief 开始计时
void Snake::start(){
    startTime = std::chrono::system_clock::now();
}

/// @brief 更新时间
void Snake::updateTime(){
    std::chrono::system_clock::time_point specific_time = std::chrono::system_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(specific_time - startTime).count()/double(1000);
}