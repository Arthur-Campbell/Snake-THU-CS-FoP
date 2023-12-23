#include <windows.h>
#include <conio.h>
#include <iostream>

/// @brief 这部分是打印部分，用于在CLI上完成游戏及调试.使用GUI相关代码将这一部分覆盖或重写一份show.cpp

// TODO::可以在原有部分已经完成的基础上增加皮肤功能，包括地图皮肤和蛇皮肤，以及与之相关的积分兑换，积分管理系统。
// 以及道具系统等。

// 这个函数用于将光标置于x,y位置，使得更改发生在局部。
void gotoxy(short x, short y)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hOut, pos);
}

// 将光标隐藏起来，美化界面
void HideCursor()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
}

