#include <iostream>
#include <fstream>
#include <string>
#include <map>
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
    ifstream myfile(argv[2]);
    if (!myfile.is_open())
    {
        cout << "Unable to open file " << argv[2];
        usage();
        exit(1);
    }

    map<string, int> word_count;
    map<string, map<char, int> > word_follow_count;
   
    while (true){
        string chunk(input_word_size, '\0');
        char next_letter;
        myfile.read(&chunk[0], input_word_size);
        streamsize bytes_read = myfile.gcount();

        if (bytes_read != input_word_size) {
            break;
        }
        if (!myfile){
            break;
        }
        myfile.read(&next_letter, 1);

        myfile.seekg(-1, ios_base::cur);

        word_follow_count[chunk][next_letter]++;
        word_count[chunk]++;
    }
    cout << "start" <<endl;
    for (const auto& pair : word_follow_count) {
        for (const auto& pair2 : pair.second) {
            cout << "'" << pair.first << "' : " << pair2.first << ":" << pair2.second << endl;

        }
       // cout << "done" <<endl;
    }

    return 0;
}

