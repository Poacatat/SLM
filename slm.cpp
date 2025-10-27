#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <random>
using namespace std;

void usage(){
    cout << "Usage\n\nslm <INPUT WORD LENGTH> <INPUT FILE> <OUTPUT WORD LENGTH>" << endl;
}

int input_number(char* arg){
    try {
        
        int input = stoi(arg);
        return input;

    }
        catch (invalid_argument const& ex) {
        cout << "Invalid argument " << arg << endl;
        usage();
        exit(1);
    } 
}


int main (int argc, char *argv[]) {
    if (argc != 4){
        usage();
        return 0;
    }

    int input_word_size  = input_number(argv[1]);
    int output_word_zise = input_number(argv[3]);

    
    
    string line;
    model.pick_start_word()
    model.train()
    
    //for (const auto& pair : word_count){
    //    cout << pair.first << ":" <<pair.second<<"end"<<endl;
    //}
    //cout << "start" <<endl;
    //for (const auto& pair : word_follow_count) {
    //    for (const auto& pair2 : pair.second) {
    //       cout << "'" << pair.first << "' : '" << pair2.first << "': " << pair2.second << endl;

    //    }
    //}


    int chars_printed = input_word_size;

    string current_word = pick_start_word(word_count);

    cout << "begin " << endl<<current_word;
    while (chars_printed<output_word_zise){
        char next_char = calculate_next_char(current_word, word_count, word_follow_count);
        cout<<next_char;
        current_word.erase(0,1);
        current_word+=next_char;
        chars_printed += 1;
    }
    //cout << "end " << endl<<current_word;

    cout << endl;

    return 0;
}

