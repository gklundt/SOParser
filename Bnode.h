#ifndef SOPARSER_BNODE_H
#define SOPARSER_BNODE_H


class Bnode {
public:
    Bnode(char *line_text, int line_number) : line(line_text),
                                              lineNumber(line_number),
                                              left(0), right(0) { }

    int lineNumber;
    char *line;
    Bnode *left;
    Bnode *right;
};



#endif //SOPARSER_BNODE_H
