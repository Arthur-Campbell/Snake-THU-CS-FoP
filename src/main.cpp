#include "introduction.h"
#include "menu.h"
#include <iostream>

int main () {
    bool out = false;
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