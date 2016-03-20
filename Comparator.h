//
// Created by gordon on 3/20/16.
//

#ifndef SOPARSER_COMPARATOR_H
#define SOPARSER_COMPARATOR_H


using namespace std;
class Comparator {
public:
    virtual int Compare(const char *lhs, const char *rhs) = 0;
};


#endif //SOPARSER_COMPARATOR_H
