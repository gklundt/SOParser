/**
 * Project Untitled
 */


#include "SortProcessor.h"
#include "MapReader.h"

void SortProcessor::Process(Data &data) {

    MapReader mapReader;
    int curr_line = 0;
    for (vector<Word>::iterator it = data.output_map.begin();
         it != data.output_map.end();
         ++it) {

        if (it->line == curr_line) {
            Bnode *node = new Bnode;
            node->line = mapReader.getLine(data, curr_line);
            node->lineNumber = curr_line;
            node->left = 0;
            node->right = 0;
            if (!my_root) {
                my_root = node;
            } else {
                fillTree(my_root, node);
            }
            curr_line++;
        }
    }


    int order = 0;
    parseTree(my_root, order);
    reorder_word_vector(data);
    data.output_map.swap(vw);

}

void SortProcessor::fillTree(Bnode *root, Bnode *node) {
    if (Compare(root->line, node->line) > 0) {
        if (root->left == 0) {
            root->left = node;
        } else {
            fillTree(root->left, node);
        }
    } else {
        if (root->right == 0) {
            root->right = node;
        } else {
            fillTree(root->right, node);
        }
    }
}

void SortProcessor::parseTree(Bnode *root, int &order) {

    pair<int, int> p;
    if (root->left) { parseTree(root->left, order); }

    order++;
    p.first = order;
    p.second = root->lineNumber;
    sort_map.insert(p);

    if (root->right) { parseTree(root->right, order); }

}


int SortProcessor::Compare(const char *lhs, const char *rhs) {


    int pos = 0;

    const char *l = lhs;
    const char *r = rhs;
    for (; ; ++pos) {


        int li = l[pos];
        int ri = r[pos];

        int lli = li, rri = ri;


        if (li >= 65 && li <= 90) { lli = (li + 33) + ((li + 33) - 98); }
        if (li >= 97 && li <= 122) { lli = li + (li - 97); }

        if (ri >= 65 && ri <= 90) { rri = (ri + 33) + ((ri + 33) - 98); }
        if (ri >= 97 && ri <= 122) { rri = ri + (ri - 97); }


        if (lli > rri) {
            return 1;
        }
        if (lli < rri) {
            return -1;
        }
        if (l[pos] == '\0') {
            return 0;
        }
    }

}

void SortProcessor::reorder_word_vector(Data &data) {

    for (int i = 1; i <= sort_map.size(); ++i) {
        int v = sort_map.at(i);
        for(vector<Word>::iterator it = data.output_map.begin();
            it != data.output_map.end();
            ++it){
            if(v == it->line){
                push_word(it->length, i, it->word, it->position, vw);
            }
        }
    }

}












