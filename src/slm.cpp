#include "Generator.h"
#include <iostream>
using namespace std;
int main (int argc, char *argv[]) {
    if (argc != 4){
        Generator::usage();
        return 0;
    }

    int input_word_size  = Generator::parse_number(argv[1]);
    std::string filename = argv[2];
    int output_size = Generator::parse_number(argv[3]);
    if (input_word_size <= 0 || output_size <=0){
        cout << "Invalid input or output size." << endl;
        Generator::usage();
        return 0;
    }
    Generator::generate(input_word_size, filename, output_size);

    return 0;
}

