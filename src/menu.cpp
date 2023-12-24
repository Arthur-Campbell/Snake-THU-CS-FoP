#include <iostream>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "config.h"
#include "map.h"
#include "record.h"
#include "game.h"

void menu()
{   std::string m = "default";
    std::string c = "default";
    static Config config = Config();
    static Map map = Map();
    map.buildMap();
    while(1){
    bool trigger = false;
    while (trigger == false)
    {
        system("cls");
        std::cout << "MAP EDITOR" << std::endl;
        std::cout << "n         --Create a new map" << std::endl;
        std::cout << "m         --Load your map" << std::endl;
        std::cout << "CONFIFURATION EDITOR" << std::endl;
        std::cout << "i         --Create a new configuration" << std::endl;
        std::cout << "u         --Load your configuration" << std::endl;
        std::cout << "LOAD RECORD" << std::endl;
        std::cout << "r         --load your record" << std::endl;
        std::cout << "g         --Go! Go! Go!" << std::endl;
        std::cout << "q         --Quit" << std::endl;
        std::cout << "Please Enter Your Choice" << std::endl;
        char ch;
        ch = std::getchar();
        switch (ch)
        {
        case 'n':
            writeMap();
            break;
        case 'm':
            map = readMap(m);
            break;
        case 'i':
            writeConfig();
            break;
        case 'u':
            config = readConfig(c);
            break;
        case 'g':
            trigger = true;
            break;
        case 'q':
            exit(0);
            break;
        case 'r':
            readRecord();
            break;
        default:
            break;
        }
        Sleep(200);
    }
    game(config, map, m, c);
    }
}

