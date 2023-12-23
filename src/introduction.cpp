#include <iostream>

/// @brief 介绍游戏的操作
void introduce(){
        std::cout << "Welcome to Snake for CLI" << std::endl;
        std::cout << "This Is Just A Introduction For You, Nothing But \'p\' is valid. Press \'p\' To Go Back To The Memu" << std::endl;
        std::cout << "\'w\'  \'a\'   \'s\'   \'d\'               control the snake" << std::endl;
        std::cout << "\'q\'                                   quit the game" << std::endl;
        std::cout << " \'space\'                             pause the game" << std::endl;
        std::cout << "\'g\'                                      start the game" << std::endl;
        std::cout << " \'i\'                                      create a new configuration" << std::endl;
        std::cout << " \'u\'                                     load your configutration" << std::endl;
        std::cout << " \'n\'                                     create a new map" << std::endl;
        std::cout << " \'m\'                                    load your configutration" << std::endl;
        char ch;
        while((ch = std::getchar()) != 'p');
}