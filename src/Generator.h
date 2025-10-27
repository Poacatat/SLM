#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include "Model.h"

class Generator {
public:
    static void usage();
    static int parse_number(const char* arg);
    static void generate(int input_word_size, const std::string& filename, int output_word_size);
};

#endif
