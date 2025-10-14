#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void usage(){
    cout << "Usage\n\nslm <INPUT WORD LENGTH> <INPUT FILE> <OUTPUT LENGTH>" << endl;
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

    try {
        
        string line;
        ifstream myfile(argv[2]);
        if (!myfile.is_open())
        {
            cout << "Unable to open file " << argv[2];
            
        }

    }
        catch (invalid_argument const& ex) {
        cout << "didnt work " <<ex.what()<<endl;
        usage();
    } 

    return 0;
}

