#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <string>

/// @brief Config类的定义,用于储存配置信息
struct Config {
    int difficulty ;
    long long seed;
    int applenum;
    double one;
    double two;
    double three;

    Config();

    void init();

};

/// @brief 读取配置文件
Config readConfig(std::string &s);

/// @brief 写入配置文件
void writeConfig();

#endif