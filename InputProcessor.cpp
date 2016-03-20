#include "InputProcessor.h"

using namespace std;

void InputProcessor::Process(Data &data) {

    int line = 0, word = 0, length = 0, pos = 0;

    while (true) {
        if (data.input[pos] == '\0') {
            break;
        }

        if (data.input[pos] == '\r' || data.input[pos] == '\n') {
            if(length > 0){
                push_word(length, line, word, pos-length, vw);
                line++;
                word = 0;
            }
            length = 0;
            ++pos;
            continue;
        }

        if (data.input[pos] == '\t' || data.input[pos] == ' ') {
            if(length > 0){
                push_word(length, line, word, pos-length, vw);
                word++;
            }
            length = 0;
            ++pos;
            continue;
        }

        length++;
        ++pos;
    }

    if (length > 0) {
        push_word(length, line, word, pos-length, vw);
    }


    data.output_map.swap(vw);

}

