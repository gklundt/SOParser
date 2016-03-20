/**
 * Project Untitled
 */


#ifndef _OUTPUTPROCESSOR_H
#define _OUTPUTPROCESSOR_H

#include <set>
#include "Processor.h"
#include "Comparator.h"

using namespace std;

class OutputProcessor : public Processor, public Comparator {
public:
    OutputProcessor() ;

    int Compare(const char *lhs, const char *rhs);

    void Process(Data &data);

private:
    vector<Word> vw;
    set<char *> myset;

};

#endif //_OUTPUTPROCESSOR_H