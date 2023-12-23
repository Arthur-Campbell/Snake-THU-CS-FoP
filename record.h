#ifndef RECORD_H
#define RECORD_H	


#include "snake.h"
#include <string>

void writeRecord(Snake obj, std::string m, std::string c);

void recordPrintConfAndMapName(P mapsize, std::string m, std::string c);

void readRecord();

#endif // !RECORD_H