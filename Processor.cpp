#include "Processor.h"

void Processor::push_word(int length, int line, int word, int pos,
               vector<Word> &vw) {

    Word w;
    w.length = length;
    w.line = line;
    w.word = word;
    w.position = pos;
    vw.push_back(w);

}

