//
// Created by gordon on 3/19/16.
//

#include "Data.h"
#include "Word.h"
#include <vector>
#ifndef SOPARSER_MAPREADER_H
#define SOPARSER_MAPREADER_H

using namespace std;
class MapReader {

public:
    char *getLine(Data & data, int line);

    char *getWord(Data & data, int line, int word);

    char *getOutput(Data & data);

};


#endif //SOPARSER_MAPREADER_H
