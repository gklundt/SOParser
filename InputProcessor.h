#ifndef _INPUTPROCESSOR_H
#define _INPUTPROCESSOR_H

#include "Processor.h"

using namespace std;

class InputProcessor : public Processor {

public:
    void Process(Data &data);

private:
    vector<Word> vw;

};


#endif //_INPUTPROCESSOR_H