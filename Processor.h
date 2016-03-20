/**
 * Project Untitled
 */

#include <iostream>
#include <cstring>
#include <vector>

#include "Data.h"
#include "Word.h"

#ifndef _PROCESSOR_H
#define _PROCESSOR_H

using namespace std;

class Processor {
public:
    virtual void Process(Data &data) = 0;

protected:
    void push_word(int length, int line, int word, int pos,
                   vector<Word> &vw);


};


#endif //_PROCESSOR_H