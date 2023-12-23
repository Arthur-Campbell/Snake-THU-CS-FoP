#include "introduction.h"
#include "menu.h"
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <string>
#include <iostream>

int main () {
    bool out = false;
    std::string configName = "config";
    std::string mapName = "maps";
    std::string recordName = "record";
    try {
    fs::create_directories(configName);
    fs::create_directories(mapName);
    fs::create_directories(recordName);
    }
    catch (const std::experimental::filesystem::filesystem_error& e) {}
    while(out == false){
    system("cls");
    std::cout << "Snake" << std::endl;
    std::cout << "Wanna Some introductions?" << std::endl;
    std::cout << "1. Yes                2.Straight Forward Game" << std::endl;
    int choice;
    while(1){
    std::cin >> choice;
    if(choice == 1){
        introduce();
        break;
    }
    else if(choice == 2)
        out = true;
        break;
    }
}
    menu();
    return 0;
}
