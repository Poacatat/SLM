#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <map>
using namespace std;

class Model{
    private:
        int input_word_size;
        map<string, int> word_count;
        map<string, map<char, int> > word_follow_count;

    public:
        Model(int input_word_size);

        void train(const std::string& filename);
        std::string pick_start_word() const;
        char calculate_next_char(const std::string& currentWord) const;

};

#endif