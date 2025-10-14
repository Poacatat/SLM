// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file. Made and execured in one file. I am also writing this using touch typing.\n";
  myfile.close();
  return 0;
}
