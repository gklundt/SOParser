#include <iostream>
#include "Data.h"
#include "StreamAdapter.h"
#include "Processor.h"
#include "InputProcessor.h"
#include "MapReader.h"
#include "CircularShiftProcessor.h"
#include "SortProcessor.h"
#include "OutputProcessor.h"


int main() {

//    char *input = (char *) "Yoda is a Jedi\n"
//            "I don't like jelly\n"
//            "Jumping Jesus on a pogo stick\n"
//            "University of North Columbia\n"
//            "University of North Dakota\n"
//            "University of North Bali\n"
//            "biggest star in the universe";


    string input_string;
    string input_line;

    while (getline(cin, input_line)) {
        input_string.append("\n" + input_line);
    }
    char *input = new char[input_string.length() + 1];
    strcpy(input, input_string.c_str());

    Data data;

    StreamAdapter readin;
    readin.Read(input, data);

    Processor *input_processor = new InputProcessor();
    Processor *shift_processor = new CircularShiftProcessor();
    Processor *sort_processor = new SortProcessor();
    Processor *output_processor = new OutputProcessor();

    input_processor->Process(data);
    shift_processor->Process(data);
    sort_processor->Process(data);
    output_processor->Process(data);

    MapReader mr;
    char *n = mr.getOutput(data);

    cout << n << endl;

    delete input_processor;
    delete shift_processor;
    delete sort_processor;
    delete output_processor;

    return 0;
}