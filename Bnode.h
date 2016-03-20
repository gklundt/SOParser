#ifndef SOPARSER_BNODE_H
#define SOPARSER_BNODE_H


class Bnode {
public:
    int lineNumber;
    char *line;
    Bnode *left;
    Bnode *right;
};


#endif //SOPARSER_BNODE_H
