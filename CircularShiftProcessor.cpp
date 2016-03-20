#include <queue>
#include "CircularShiftProcessor.h"

int CircularShiftProcessor::twist(int line, int last_word,
                                  vector<int> &len, vector<int> &pos) {

    for (int i = 0; i <= last_word; ++i) {
        for (int j = 0; j <= last_word; ++j) {
            int shift = j + i > last_word ? (j + i) - (last_word + 1) : j + i;

            int wl = len.at((unsigned long) shift);
            int wp = pos.at((unsigned long) shift);

            push_word(wl, line, j, wp, vw);
        }
        line++;
    }
    return line;
}

void CircularShiftProcessor::Process(Data &data) {

    vector<int> len;
    vector<int> pos;

    int circ_line = 0;
    int circ_word = 0;
    int curr_line = 0;

    for (vector<Word>::iterator it = data.output_map.begin();
         it != data.output_map.end();
         ++it) {

        if (it->line > curr_line) {
            circ_line = twist(circ_line, circ_word, len, pos);
            len.clear();
            pos.clear();
        }

        len.push_back(it->length);
        pos.push_back(it->position);

        circ_word = it->word;
        curr_line = it->line;
    }

    twist(circ_line, circ_word, len, pos);

    data.output_map.swap(vw);
}