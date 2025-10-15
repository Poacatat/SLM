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

char calculate_next_char(string current_word, map<string, int> word_count, map<string, map<char, int> > word_follow_count){
    int sum = word_count[current_word];
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,sum);
    int r = dist(rng);
    cout << "r is " << r << endl;
    for (const auto& pair : word_follow_count[current_word]){
        r -= pair.second;
        if (r <= 0){
            return pair.first;
        }
    }
    cout << "There is a bug in the calculate_next_char fucntion" << endl; 
    return 'q';

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
        // Vi läser in först en input_word_size mängd karaktärer 
        // Checkor EOF och liknande
        // LÄser in nästa char för att få den datan, sen flyttar vi tillbaka pointern ett steg.

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
    }
    int a = 0;
    int b = 0;
    int c = 0;

    for (int i =0; i<1000; i++){
        char random_char = calculate_next_char("hu", word_count, word_follow_count);
        if (random_char == 'a'){
            a++;
        }
        if (random_char == 'b'){
            b++;
        }
        if (random_char == 'c'){
            c++;
        }
//        cout << random_char << endl<<endl;
    }
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}

