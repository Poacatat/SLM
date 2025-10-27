#include "Generator.h"

int main (int argc, char *argv[]) {
    if (argc != 4){
        Generator::usage();
        return 0;
    }

    int input_word_size  = Generator::parse_number(argv[1]);
    std::string filename = argv[2];
    int output_word_size = Generator::parse_number(argv[3]);

    Generator::generate(input_word_size, filename, output_word_size);

    return 0;
}

