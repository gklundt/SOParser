#ifndef _SORTPROCESSOR_H
#define _SORTPROCESSOR_H

#include <map>
#include "Processor.h"
#include "Comparator.h"
#include "MapReader.h"

using namespace std;

struct Bnode {
    int lineNumber;
    char *line;
    Bnode *left;
    Bnode *right;
};

class SortProcessor : public Processor, public Comparator {

public:

    int Compare(const char *lhs, const char *rhs);

    void Process(Data &data);


private:
    vector<Word> vw;
    Bnode *my_root;

    void fillTree(Bnode *root, Bnode *node);

    void parseTree(Bnode *root, int &order);

    map<int, int> sort_map;

    void reorder_word_vector(Data &data);

};

#endif //_SORTPROCESSOR_H