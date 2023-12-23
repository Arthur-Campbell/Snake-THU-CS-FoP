/// @brief P类的定义
/// @param x,y,points
/// P类是一个简单的二维坐标类，用于储存坐标数据
/// 由于P类的数据成员都是public的，所以可以直接使用P.x和P.y来访问坐标数据
/// 也可以使用P.x()和P.y()来访问坐标数据
///重载了==,!=运算符，可以直接使用==,!=来比较两个P类对象是否相等
#ifndef P_H
#define P_H

struct P {
    int x, y;
    int  points;//标记苹果的分值
    P(int x = 0, int y = 0,int points = 1) : x(x), y(y), points(points){}
    P operator+(const P &b) const { return P(x + b.x, y + b.y); }

    bool operator==(const P &b) const { return x == b.x && y == b.y; }

    bool operator!=(const P &b) const { return !(*this == b); }
};

#endif //P_H