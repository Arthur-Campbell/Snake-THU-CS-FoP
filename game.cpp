#include "snake.h"
#include "config.h"
#include "map.h"
#include "print.h"
#include <ctime>
#include <cstdlib>
#include "game.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

static bool gameover = false;

void game(Config config,Map map){
    Snake obj = Snake(config,map);
    obj.config.init();
    while(gameover == false){
        system("cls");
        HideCursor();
        obj.printApple();
        obj.printBody();
        obj.printMap();
        obj.printScore();
        obj.printTime();
        Oper(obj, map);
        obj.Snake::move();
        obj.eatApple();
        obj.updateTime();
        obj.printTime();
        if(obj.crashWall(obj.body.back())){
            obj.printRedBody();
            gameOver(map.mapsize);
        }
        if(obj.crashBody(obj.body.back(),false)){
            obj.printRedBody();
            gameOver(map.mapsize);
        }
        obj._sleep();
    }
}

void gameOver(P mapsize){
    gotoxy(mapsize.x / 2, mapsize.y + 2);
    std::cout << "Game Over, \'b\' to record it, other bottons to quit";
    system("pause");
    char ch;
    if( (ch = _getch()) == 'b'){
        //TODO::record
    }
    gameover = true;
}

void Oper(Snake &obj , Map map){
     if(_kbhit()){
        char ch = _getch();
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
}

void pause(P mapsize)
{
    gotoxy(mapsize.x / 2, mapsize.y + 2);
    std::cout << "Game is pending, 'q' to back to menu, any other botton to continue";
    system("pause");
    char ch;
    if( (ch = _getch()) == 'q'){
        gameover = true;
    }
}
