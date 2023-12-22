#include <iostream>
#include <setjmp.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "config.h"
#include "map.h"
#include "game.h"

jmp_buf menutab;

void menu()
{
    static Config config = Config();
    static Map map = Map();
    setjmp(menutab);
    bool trigger = false;

    char ch;
    while (trigger == false)
    {
        system("cls");
        std::cout << "MAP EDITOR" << std::endl;
        std::cout << "n         --Create a new map" << std::endl;
        std::cout << "m         --Load your map" << std::endl;
        std::cout << "CONFIFURATION EDITOR" << std::endl;
        std::cout << "i         --Create a new configuration" << std::endl;
        std::cout << "u         --Load your configuration" << std::endl;
        std::cout << "g         --Go! Go! Go!" << std::endl;
        std::cout << "q         --Quit" << std::endl;
        std::cout << "Please Enter Your Choice" << std::endl;
        ch = std::getchar();
        switch (ch)
        {
        case 'n':
            writeMap();
            break;
        case 'm':
            map = readMap();
            break;
        case 'i':
            writeConfig();
            break;
        case 'u':
            config = readConfig();
            break;
        case 'g':
            trigger = true;
            break;
        case 'q':
            exit(0);
            break;
        default:
            break;
        }
        Sleep(200);
    }
    game(config, map);
    longjmp(menutab, 1);
}

