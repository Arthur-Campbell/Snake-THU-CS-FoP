#ifndef CONFIG_H
#define CONFIG_H

/// @brief Config类的定义,用于储存配置信息
struct Config {
    int difficulty ;
    int seed;
    int applenum;
    double one;
    double two;
    double three;

    Config();

    void init();

};

/// @brief 读取配置文件
Config readConfig();

/// @brief 写入配置文件
void writeConfig();

#endif