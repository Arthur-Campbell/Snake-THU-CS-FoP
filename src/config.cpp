#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <io.h>
#include "config.h"

//构造函数，也是默认配置
Config::Config(){
        difficulty = 1;
        seed = -1;
        applenum = 1;
        one = 0.6;
        two = 0.3;
        three = 0.1;
}

//根据配置设置随机种子
void Config::init(){
    if(seed == -1){
        seed = time(NULL);
    }
    srand(seed);
}

//载入配置文件，主要流程是：读入有效文件名，将文件内容读入并对config赋值，返回一个配置文件的config
Config readConfig(std::string &s) {
        system("cls");
        Config config = Config();
        std::string name;
        std::cout<<"input configuration name(only support English characters, numbers, underscores, slashes, press 'q' and enter to exit)"<<std::endl;
        while(1)  {
            std::cin>>name;
            if(name == "q") {
                s = "default";
                return config;
            }
            s = name;
            std::string filename = "../config/" + name + ".config";
            std::fstream file(filename, std::ios::in);
            if(file.is_open()) {
            file >> config.difficulty;
            file >> config.seed;
            file >> config.applenum;
            file >> config.one >> config.two >> config.three;
            file.close();
            break;
            }
            else{
                std::cout<<"No such configuration, please re-enter the configuration name"<<std::endl;
            }
        }
        std::cout << "Configuration load successfully" << std::endl;
        return config;
}

//创建配置，主要流程为:获取有效文件名， 读入用户输入，按照顺序写入文件
void writeConfig(){
    system("cls");
    std::cout<<"input configuration name(only support English characters, numbers, underscores, slashes, press 'q' and enter to exit)"<<'\n';
    std::string name;
    std::cin>>name;
    std::string filename = "../config/" + name + ".config";
        //写入难度
    std::cout<<"input difficulty(1-10):"<<'\n';
    int difficulty;
    while(1){
    std::cin>>difficulty;
    if(difficulty>0&&difficulty<11) break;
    else{
        std::cout<<"difficulty must be between 1 and 10, please re-enter"<<'\n';
    }
    }
        //写入随机种子
    std::cout<<"please input seed(-1 for random seed):"<<'\n';
    long long seed;
    while(1){
    std::cin>>seed;
    if(seed>-2) break;
    else{
        std::cout<<"seed must be greater than -2, please re-enter"<<'\n';
    }
    }
        //写入苹果数量
    std::cout<<"please input apple number(1-5)"<<'\n';
    int applenum;
    while(1){
    std::cin>>applenum;
    if(applenum>0&&applenum<6) break;
    else{
        std::cout<<"appple number must be between 1 and 5, please re-enter"<<'\n';
    }
    }
        //写入三种分数苹果的概率
    std::cout<<" please input apple probability in the format of \'one\'  \'two\'  \'three\'(0-1)"<<'\n';
    double one,two,three;
    while(1){
    std::cin>>one>>two>>three;
    if((one+two+three - 1)<1e-5) 
        break;
    else{
        std::cout<<" the sum of three probability must be 1, please re-enter"<<'\n';
    }
    }
    std::fstream fout(filename, std::ios::out);
    if(!fout.is_open()){
        std::cerr<<"Error: Can't create file"<<std::endl;
    }
        //按顺序写入
    fout<<difficulty<<std::endl<<seed<<std::endl<<applenum<<std::endl<<one<<" "<<two<<" "<<three;
    fout.close();
}
