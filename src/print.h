/// @brief 这部分是打印部分，用于在控制台光标操控下打印游戏界面
#ifndef PRINT_H
#define PRINT_H

/// @brief 光标移动到(x,y)
void gotoxy(short x, short y);

/// @ brief 隐藏光标，美化输出
void HideCursor();
#endif  // PRINT_H