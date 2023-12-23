#include "record.h"
#include "snake.h"
#include "print.h"
#include <string>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <io.h>
#include <vector>
#include "config.h"
#include "P.h"
#include "map.h"


/// @brief 向文件中写入记录
void writeRecord(Snake obj, std::string m, std::string c) {
    system("cls");
    std::cout << "input record name(only support English characters, numbers, underscores, slashes, press 'q' and enter to exit)" << '\n';
    std::string name;
    std::cin >> name;
    std::string filename = "../record/" + name + ".rec";
    std::fstream fout(filename, std::ios::out);
    if (!fout.is_open()) {
        std::cerr << "Error: Can't create file" << std::endl;
        return;
    }
    fout << m << std::endl<< c << std::endl;
    fout << obj.config.difficulty << std::endl << obj.config.seed << std::endl << obj.config.applenum << std::endl;
    fout << obj.config.one << " " << obj.config.two << " " << obj.config.three << std::endl;
    fout << obj.map.mapsize.x << " " << obj.map.mapsize.y << std::endl;
    fout << obj.map.left << " " << obj.map.up << " " << obj.map.right << " " << obj.map.down << std::endl;
    fout << obj.map.obstacleNum << std::endl;
    for (int i = 0; i < obj.map.obstacleNum; i++) {
        fout << obj.map.obstacle[i].x <<" " << obj.map.obstacle[i].y << std::endl;
    }
    for (int i = 0; i < obj.ops.size(); i++) {
        fout << obj.ops[i].x << " " << obj.ops[i].y << std::endl;
    }
}

void recordPrintConfAndMapName(P mapsize, std::string m, std::string c) {
    gotoxy(0, mapsize.y + 5);
    std::cout << "Map:           " << m;
    gotoxy(0, mapsize.y + 6);
    std::cout << "Configuration: " << c;
}

/// @brief 读取位于文件夹record下的记录文件
void readRecord() {
    system("cls");
    Map map = Map();
    Config config = Config();
    std::string name;
    std::cout << "input record name(only support English characters, numbers, underscores, slashes, press 'q' and enter to exit)" << '\n';
    while(1){
    std::cin >> name;
    if (name == "q")
       return;
    std::string filename = "../record/" + name + ".rec";
    std::fstream file(filename, std::ios::in);
    if (file.is_open()) {
        std::string m;
        std::string c;
        file >> m >> c;
        file >> config.difficulty >> config.seed >> config.applenum;
        file >> config.one >> config.two >> config.three;
        file >> map.mapsize.x >> map.mapsize.y;
        file >> map.left >> map.up >> map.right >> map.down;
        map.obstacle.clear();
        file >> map.obstacleNum;
        for (int i = 0; i < map.obstacleNum; i++) {
            int x, y;
            file >> x >> y;
            map.obstacle.push_back(P(x, y));
        }
        map.buildMap();
        Snake obj = Snake(config, map);
        obj.config.init();
        while (1) {
            system("cls");
            HideCursor();
            obj.appleGenerate();
            obj.printApple();
            obj.printMap();
            obj.printScore();
            recordPrintConfAndMapName(map.mapsize,m,c);
            int _x_, _y_;
            file >> _x_ >> _y_;
            if (_x_ == 0 && _y_ == -1) {
                obj.up();
            }
            else if (_x_ == 0 && _y_ == 1) {
                obj.down();
            }
            else if (_x_ == -1 && _y_ == 0) {
                obj.left();
            }
            else if (_x_ == 1 && _y_ == 0) {
                obj.right();
            }
            obj.Snake::move();
            if (obj.crashWall(obj.body.back())) {
                obj.printRedBody();
                gotoxy(0, map.mapsize.y + 2);
                std::cout << "Record Over, press any botton to back" << std::endl;
                char tmp = _getch();
                return;
            }
            else { obj.printBody(); }
            if (obj.crashBody(obj.body.back(), false)) {
                obj.printRedBody();
                gotoxy(0, map.mapsize.y + 2);
                std::cout << "Record Over, press any botton to back" << std::endl;
                char tmp = _getch();
                return;
            }
            else { obj.printBody(); }
            obj.eatApple();
            obj.updateTime();
            obj.printTime();
            obj._sleep();
        }
    }
    else {
        std::cerr << "Error: Can't open file" << std::endl;
     }
    }
}