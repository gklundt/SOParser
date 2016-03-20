#ifndef _CIRCULARSHIFTPROCESSOR_H
#define _CIRCULARSHIFTPROCESSOR_H

#include "Processor.h"

using namespace std;

class CircularShiftProcessor : public Processor {

public:
    void Process(Data &data);

private:
    vector<Word> vw;

    int twist(int line, int last_word,
              vector<int> &len, vector<int> &pos);

};

#endif //_CIRCULARSHIFTPROCESSOR_H