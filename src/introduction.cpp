#include <iostream>

/// @brief 介绍游戏的操作
void introduce(){
        std::cout << "Welcome to Snake for CLI" << std::endl;
        std::cout << "This Is Just A Introduction For You, Nothing But \'p\' is valid. Press \'p\' To Go Back To The Memu" << std::endl;
        std::cout << "w  a   s   d                        control the snake" << std::endl;
        std::cout << "q                                   quit" << std::endl;
        std::cout << "space                               pause the game" << std::endl;
        std::cout << "g                                   start the game" << std::endl;
        std::cout << "i                                   create a new configuration" << std::endl;
        std::cout << "u                                   load your configutration" << std::endl;
        std::cout << "n                                   create a new map" << std::endl;
        std::cout << "m                                   load your configutration" << std::endl;
        std::cout << "o x y                               Add an obstacle in (x,y)" << std::endl;
        std::cout << "p x y                               Remove an obstacle in (x,y)" << std::endl;
        std::cout << "w 0/1 in create map mode            make the upside wall disappear" << std::endl;
        std::cout << "a 0/1 in create map mode            make the leftside wall disappear" << std::endl;
        std::cout << "s 0/1 in create map mode            make the downside wall disappear" << std::endl;
        std::cout << "d 0/1 in create map mode            make the rightside wall disappear" << std::endl;
        std::cout << "f in create map mode                save the map" << std::endl;
        char ch;
        while((ch = std::getchar()) != 'p');
}
