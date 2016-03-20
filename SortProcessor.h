#ifndef _SORTPROCESSOR_H
#define _SORTPROCESSOR_H

#include <map>
#include "Processor.h"
#include "Comparator.h"
#include "MapReader.h"
#include "Bnode.h"

using namespace std;

class SortProcessor : public Processor, public Comparator {

public:

    int Compare(const char *lhs, const char *rhs);

    void Process(Data &data);


private:
    vector<Word> vw;
    Bnode *my_root;
    MapReader mapReader;

    void fillTree(Bnode *root, Bnode *node);

    void parseTree(Bnode *root, int &order);

    map<int, int> sort_map;

    void reorder_word_vector(Data &data);

};

#endif //_SORTPROCESSOR_H