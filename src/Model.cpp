#include "Model.h"
#include <iostream>
#include <fstream>
#include <random>
#include "Generator.h"

using namespace std;


Model::Model(int input_word_size) : input_word_size(input_word_size) {}

void Model::train(const string& filename){
    ifstream myfile(filename);
    if (!myfile.is_open())
    {
        cout << "Unable to open file " << filename;
        Generator::usage();
        exit(1);
    }
        
    string chunk(input_word_size, '\0');

    while (true) {

        // Vi läser in först en input_word_size mängd karaktärer 
        // Checkor EOF och liknande
        // LÄser in nästa char för att få den datan, sen flyttar vi tillbaka pointern 1 + input word count steg steg.

        myfile.read(&chunk[0], input_word_size);
        streamsize bytes_read = myfile.gcount();

        if (bytes_read < input_word_size) {
            break;
        }

        char next_letter = '\0';
        int next = myfile.peek();
        
        if (next != EOF ) {
            next_letter = static_cast<char>(next);
            word_follow_count[chunk][next_letter]++;
        }

        word_count[chunk]++;

        myfile.seekg(-(input_word_size - 1), ios_base::cur);
    }
    for (const auto& outer : word_follow_count) {
        cout << "'" << outer.first << "' follows -> ";
        for (const auto& inner : outer.second) {
            cout << "'" << inner.first << "': " << inner.second << "  ";
        }
        cout << endl;
    }
}

std::string Model::pick_start_word() const {
    int sum =0;
    for (const auto& pair : word_count){
        sum+=pair.second;
    }
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,sum);
    int r = dist(rng);
    for (const auto& pair : word_count){
        r -= pair.second;
        if (r <= 0){
            return pair.first;
        }
    }
    cout << "uh oh"<<endl;
    return 0;
}

char Model::random_letter() const {
    return pick_start_word()[0];
}

char Model::calculate_next_char(const std::string& current_word) const {
    auto it = word_follow_count.find(current_word);
    if (it == word_follow_count.end()) {
        return random_letter();
    }
    int sum = word_count.at(current_word);

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(1,sum);
    int r = dist(rng);
    
    
    //cout <<endl<< r<<endl;

    for (const auto& pair : word_follow_count.at(current_word)){
        r -= pair.second;
        if (r <= 0){
            return pair.first;
        }
    }
    
    cout << "There is a bug in the calculate_next_char fucntion" << endl << endl; 
    cout << sum;
    return ' ';
}