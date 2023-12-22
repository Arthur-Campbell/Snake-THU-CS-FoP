#include <string>
#include <fstream>
#include <iostream>
#include <io.h>
#include "map.h"

Map readMap()
{
    system("cls");
    Map curmap = Map();
    std::string name;
    std::cout << "input map name(only support English characters, numbers, underscores, slashes, press 'q' and enter to exit)" << std::endl;
    while (1)
    {
        std::cin >> name;
        if (name == "q")
        {
            return curmap;
        }
        std::string filename = "maps/" + name + ".map";
        std::ifstream file(filename);
        if (file.is_open())
        {
            file >> curmap.mapsize.x >> curmap.mapsize.y;
            file >> curmap.left >> curmap.up >> curmap.right >> curmap.down;
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
    system("cls");
    std::cout << "input map name(only support English characters, numbers, underscores, slashes, press 'q' and enter to exit)" << '\n';
    std::string name;
    std::cin >> name;
    std::string filename = "Snake/maps/" + name;
    filename = filename + ".map";

    std::cout << "input map size int he format of \'x\' \'y\'(only support 9-19" << '\n';
    int x, y;
    while (1)
    {
        std::cin >> x >> y;
        if (x > 8 && x < 20 && y > 8 && y < 20)
            break;
        else
        {
            std::cout << "map size must be between 9 and 19, please re-enter" << '\n';
        }
    }

    std::cout << "input the validation of four walls in the format of \'left\' \'up\' \'right\' \'down\'(only support 1-18)"<< '\n';
    int l, r, u, d;
    std::cin >> l >> r >> u >> d;

    std::cout << "input the number of obstacles(only support 1-15)" << '\n';
    int obstacleNum;
    while (1)
    {
        std::cin >> obstacleNum;
        if (obstacleNum > -1 && obstacleNum < 16)
            break;
        else
        {
            std::cout << "Obstacle number must be between 1 and 15, please re-enter" << '\n';
        }
    }

    std::vector<P> obstacle;
    for (int i = 0; i < obstacleNum; i++)
    {
        int a, b;
        std::cin >> a >> b;
        obstacle.push_back(P(a, b));
    }

    char *filename1 = new char[filename.length() + 1];
    for (int i = 0; i < filename.length(); i++)
    {
        filename1[i] = filename[i];
    }
    std::ofstream fout;
    fout.open(filename, std::ios::out);
    if(!fout.is_open()){
        std::cerr<<"Error: Can't create file"<<std::endl;
    }

    fout << x << " " << y << std::endl
              << l << " " << u << " " << r << " " << d << std::endl
              << obstacleNum << std::endl;
    for (int i = 0; i < obstacleNum; i++)
    {
        fout << obstacle[i].x << " " << obstacle[i].y << std::endl;
    }
    fout.close();
}