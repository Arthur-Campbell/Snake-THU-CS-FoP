#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include "print.h"
#include <io.h>
#include <conio.h>
#include "map.h"


void Map::printMap() {
    for (int i = 0; i < obstacleNum; i++) {
        gotoxy(obstacle[i].x, obstacle[i].y);
        std::cout << "\033[41m" << "+" << "\033[0m";
    }
    if (left == 0) {
        std::cout << "\033[47m";
    }
    else {
        std::cout << "\033[41m";
    }
    for (int i = 0; i <= mapsize.y; i++) {
        gotoxy(0, i);
        std::cout << "+";
    }
    std::cout << "\033[0m";
    
    if (right == 0) {
        std::cout << "\033[47m";
    }
    else {
        std::cout << "\033[41m";
    }
    for (int i = 0; i <= mapsize.y; i++) {
        gotoxy(mapsize.x, i);
        std::cout << "+";
    }
    std::cout << "\033[0m";

    if (up == 0) {
        std::cout << "\033[47m";
    }
    else {
        std::cout << "\033[41m";
    }
    for (int i = 0; i < mapsize.x; i++) {
        gotoxy(i, 0);
        std::cout << "+";
    }
    std::cout << "\033[0m";

    if (down == 0) {
        std::cout << "\033[47m";
    }
    else {
        std::cout << "\033[41m";
    }
    for (int i = 0; i < mapsize.x; i++) {
        gotoxy(i, mapsize.y);
        std::cout << "+";
    }
    std::cout << "\033[0m";
}

Map readMap(std::string &s)
{
    system("cls");
    Map curmap = Map();
    curmap.obstacle.clear();
    std::string name;
    std::cout << "input map name(only support English characters, numbers, underscores, slashes, press 'q' and enter to exit)" << std::endl;
    while (1)
    {
        std::cin >> name;
        if (name == "q")
        {
            s = "default";
            return curmap;
        }
        s = name;
        std::string filename = "../maps/" + name + ".map";
        std::fstream file(filename, std::ios::in);
        if (file.is_open())
        {
            file >> curmap.mapsize.x >> curmap.mapsize.y;
            file >> curmap.left >> curmap.right >> curmap.up >> curmap.down;
            file >> curmap.obstacleNum;
            for (int i = 0; i < curmap.obstacleNum; i++)
            {
                int a, b;
                file >> a >> b;
                curmap.obstacle.push_back(P(a, b));
            }
            file.close();
            break;
        }
        else
        {
            std::cout << "No such map, please re-enter the map name" << std::endl;
        }
    }
    curmap.buildMap();
    std::cout<<"Map load successfully"<<std::endl;
    return curmap;
}

void writeMap()
{
    Map map = Map();
    system("cls");
    std::cout << "input map name(only support English characters, numbers, underscores, slashes, press 'q' and enter to exit)" << '\n';
    std::string name;
    std::string filename;
    std::fstream fout;
    while (1) {
        std::cin >> name;
        if (name == "q") {
            return;
        }
        filename = "../maps/" + name + ".map";
        fout.open(filename, std::ios::out);
        if (!fout.is_open()) {
            std::cerr << "Error: invalid name, please input again. Press 'q' and Enter to quit" << std::endl;
        }
        else { break; }
    }
    system("cls");
    std::cerr << "input map size in the format of \'x\' \'y\'(only support 8-20)" << '\n';
    int x, y;
    while (1)
    {
        std::cin >> x >> y;
        if (x > 7 && x < 21 && y > 7 && y < 21)
            break;
        else
        {
            std::cerr << "map size must be between 8 and 20, please re-enter" << '\n';
        }
    }
    map.mapsize.x = x;
    map.mapsize.y = y;
    system("cls");
    int l(1), r(1), u(1), d(1);
    std::vector<P> obstacle;
    while (1) {
        system("cls");
        map.obstacle.clear();
        map.left = l;
        map.right = r;
        map.up = u;
        map.down = d;
        map.obstacleNum = obstacle.size();
        for (int i = 0; i < obstacle.size(); i++) {
            map.obstacle.push_back(obstacle[i]);
        }
        map.buildMap();
        map.printMap();
        char ch;
        gotoxy(0, map.mapsize.y + 2);
        std::cin >> ch;
        switch (ch) {
        case 'o':
            int _x, _y;
            std::cin >> _x >> _y;
            if (_x<0 || _x>map.mapsize.x || _y<0 || _y>map.mapsize.y) {
                std::cerr << "X or Y out of range" << std::endl;
            }
            else
            {
                obstacle.push_back(P(_x,_y));
            }
            break;
        case 'p':
            int x_, y_;
            std::cin >> x_ >> y_;
            if (x_ < 0 || x_ > map.mapsize.x || y_ < 0 || y_ > map.mapsize.y) {
                std::cerr << "X or Y out of range" << std::endl;
            }
            else
            {
                std::vector<P>::iterator iter = std::find(obstacle.begin(), obstacle.end(), P(x_, y_));
                if (iter != obstacle.end()) {
                    obstacle.erase(iter);
                }
            }
            break;
        case 'w':
            std::cin >> u;
            break;
        case 'a':
            std::cin >> l;
            break;
        case 's':
            std::cin >> d;
            break;
        case 'd':
            std::cin >> r;
            break;
        case 'f':
            fout << map.mapsize.x << " " << map.mapsize.y << std::endl
                << map.left << " " << map.right << " " << map.up << " " << map.down << std::endl
                << obstacle.size() << std::endl;
            for (int i = 0; i < obstacle.size(); i++)
            {
                fout << obstacle[i].x << " " << obstacle[i].y << std::endl;
            }
            fout.close();
            return;
        case 'q':
            fout.close();
            remove(filename.c_str());
            return;
        default:
            break;
        }
    }
}

void Map::buildMap() {
    if (left == 1) {
        for (int i = 0; i <= mapsize.y; i++) {
            obstacle.push_back(P(0, i));
        }
    }
    if (up == 1) {
        for (int i = 0; i <= mapsize.x; i++) {
            obstacle.push_back(P(i, 0));
        }
    }
    if (right == 1) {
        for (int i = 0; i <= mapsize.y; i++) {
            obstacle.push_back(P(mapsize.x, i));
        }
    }
    if (down == 1) {
        for (int i = 0; i <= mapsize.x; i++) {
            obstacle.push_back(P(i, mapsize.y));
        }
    }
}