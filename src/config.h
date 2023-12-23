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


    /// @brief 构造函数，也是默认配置
    Config();

    /// @brief 根据配置设置随机种子
    void init();

};

/// @brief 载入配置文件，主要流程是：读入有效文件名，将文件内容读入并对config赋值，返回一个配置文件的config
Config readConfig(std::string &s);

/// @brief 创建配置，主要流程为:获取有效文件名， 读入用户输入，按照顺序写入文件
void writeConfig();

#endif