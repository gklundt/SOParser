#include <iostream>
#include <cstring>
#include "MapReader.h"

char *MapReader::getLine(Data &data, int line) {

    int chars = 0;
    for (vector<Word>::iterator it = data.output_map.begin();
         it != data.output_map.end(); ++it) {
        if (it->line == line) {
            chars += it->length + 1;
        }
    }

    char *ret = new char[chars];
    ret[0] = '\0';

    for (vector<Word>::iterator it = data.output_map.begin();
         it != data.output_map.end(); ++it) {
        if (it->line == line) {
            char *x = getWord(data, it->line, it->word);
            if (x) {
                strcat(ret, x);
                strcat(ret, (const char *) " ");
            }
        }
    }

    return ret;
}

char *MapReader::getWord(Data &data, int line, int word) {
    for (vector<Word>::iterator it = data.output_map.begin();
         it != data.output_map.end(); ++it) {
        if (it->line == line && it->word == word) {
            char *in_ret = new char[it->length];
            strncpy(in_ret, data.input + it->position, (size_t) it->length);
            in_ret[it->length] = '\0';
            return in_ret;
        }
    }
    return NULL;
}

char *MapReader::getOutput(Data &data) {

    int chars = 0;
    int lines = 0;

    for (vector<Word>::iterator it = data.output_map.begin();
         it != data.output_map.end(); ++it) {
        chars += it->length + 1;
        lines = it->line;
    }

    char *ret = new char[chars];
    ret[0] = '\0';

    for (int i = 0; i <= lines; ++i) {
        char *x = getLine(data, i);
        if (x) {
            strcat(ret, x);
            strcat(ret, (const char *) "\n");
        }
    }

    return ret;

}
