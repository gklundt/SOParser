#include "OutputProcessor.h"

int OutputProcessor::Compare(const char *lhs, const char *rhs) {
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

void OutputProcessor::Process(Data &data) {

    MapReader mapReader;
    int collapse_line = -1;
    char *test_char;
    bool process = false;
    for (vector<Word>::iterator it = data.output_map.begin();
         it != data.output_map.end();
         ++it) {
        if (it->word == 0) {
            collapse_line = collapse_line == -1 ? (collapse_line = it->line)
                                                : collapse_line;
            test_char = mapReader.getWord(data, it->line, it->word);
            int i = 0;
            while (test_char[i]) {
                test_char[i] = (char) (tolower(test_char[i]));
                ++i;
            }
            for (set<char *>::iterator iterator = myset.begin();
                 iterator != myset.end();
                 ++iterator) {
                process = Compare(*iterator, test_char) != 0;
                if (!process) {
                    break;
                }
            }
            collapse_line = process ? collapse_line + 1 : collapse_line;
        }
        if (process) {

            push_word(it->length, collapse_line, it->word, it->position, vw);
        }
    }

    data.output_map.swap(vw);
}

OutputProcessor::OutputProcessor() {
    int noiseword_count = 15;
    char *noisewords[] = {
            (char *) "a",
            (char *) "an",
            (char *) "the",
            (char *) "and",
            (char *) "or",
            (char *) "of",
            (char *) "to",
            (char *) "be",
            (char *) "is",
            (char *) "in",
            (char *) "out",
            (char *) "by",
            (char *) "as",
            (char *) "at",
            (char *) "off"
    };
    myset.insert(noisewords, noisewords + noiseword_count);
}



