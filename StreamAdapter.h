/**
 * Project Untitled
 */

#include <iostream>

#ifndef _STREAMADAPTER_H
#define _STREAMADAPTER_H

#include "Data.h"

using namespace std;

class StreamAdapter {
public:

    /**
     * @param instr
     * @param & data
     */
    void Read(char * instr, Data &data) {
        data.input = instr;
    }

    /**
     * @param instr
     * @param & data
     */
    char *Write(Data &data) {
        return data.input;
    }
};

#endif //_STREAMADAPTER_H