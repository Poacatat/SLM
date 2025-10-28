#include "Generator.h"
#include <iostream>

using namespace std;

void Generator::usage() {
    cout << "Usage:\n\nslm <INPUT WORD LENGTH> <INPUT FILE> <OUTPUT WORD LENGTH>\n";
}

int Generator::parse_number(const char* arg) {
    try {
        
        return stoi(arg);
    } catch (invalid_argument&) {
        cerr << "Invalid argument " << arg << endl;
        usage();
        exit(1);
    } 
}

void Generator::generate(int input_word_size, const string& filename, int output_word_zise){
    Model model(input_word_size);
    model.train(filename);
    string current_word = model.pick_start_word();

    cout << "begin " << endl<<current_word;
    int chars_printed = input_word_size;
    while (chars_printed<output_word_zise){
        char next_char = model.calculate_next_char(current_word);
        cout<<next_char;
        current_word.erase(0,1);
        current_word+=next_char;
        chars_printed ++;
    }
    cout << endl;
}