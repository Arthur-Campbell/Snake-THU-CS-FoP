#include "snake.h"
#include "config.h"
#include "map.h"
#include "print.h"
#include <ctime>
#include <cstdlib>
#include "game.h"
#include "record.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>

/// @brief 标记游戏是否结束
static bool gameover = false;

/// @brief 打印配置名和地图名
void printConfAndMapName(P mapsize, std::string m, std::string c) {
    gotoxy(0, mapsize.y + 5);
    std::cout<<"Map:            "<< m;
    gotoxy(0, mapsize.y + 6);
    std::cout << "Configuration:" << c;
}

/// @brief 游戏主体，由map和config唯一决定
void game(Config config, Map map, std::string m, std::string c) {
    Snake obj = Snake(config, map);
    obj.config.init();
    while (gameover == false) {
        system("cls");
        HideCursor();
        obj.appleGenerate();
        obj.printApple();
        obj.printMap();
        obj.printScore();
        obj.printTime();
        printConfAndMapName(map.mapsize, m, c);
        char ch = '+';
        while (_kbhit()) {
            ch = _getch();
        }
        Oper(obj, map, ch);
        obj.Snake::move();
        if (obj.crashWall(obj.body.back())) {
            obj.printRedBody();
            gameOver(map.mapsize, obj, m, c);
        }
        else { obj.printBody(); }
        if (obj.crashBody(obj.body.back(), false)) {
            obj.printRedBody();
            gameOver(map.mapsize, obj, m, c);
        }
        else { obj.printBody(); }
        obj.eatApple();
        obj.updateTime();
        obj.printTime();
        obj._sleep();
    }
        gameover = false;
}

/// @brief 游戏结束，输出结束文字
void gameOver(P mapsize, Snake obj, std::string m, std::string c){
    gotoxy(0,mapsize.y + 2);
    std::cout << "Game Over, \'b\' to record it, other bottons to quit";

    char ch;
    if( (ch = _getch()) == 'b'){
        writeRecord(obj,m,c);
    }
    gameover = true;
}

/// @brief 读取操作，并作出相应反应
void Oper(Snake &obj , Map map, char ch){
        switch (ch)
        {
        case 'w': // go up
            obj.up();
            break;
        case 'a': // go left
            obj.left();
            break;
        case 's': // go down
            obj.down();
            break;
        case 'd': // go right
            obj.right();
            break;
        case ' ': // pause
            pause(map.mapsize);
            break;
        default:
            break;
    }
}

/// @brief 暂停
void pause(P mapsize)
{
    gotoxy(0,mapsize.y + 2);
    std::cout << "Game is pending, 'q' to back to menu, any other botton to continue";
    char ch;
    if( (ch = _getch()) == 'q'){
        gameover = true;
    }
}
