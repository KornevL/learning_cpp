#include <fstream>
#include <string>
using namespace std;

int main() {

    ofstream rewrite("output.txt"); 
    rewrite.write("", 0); 
    rewrite.close();

    ifstream input("input.txt");
    ofstream output("output.txt", ios::app);
    string line;
    if (input) {
        while (getline(input, line)) {
            output << line << endl;
        }
    }
    return 0;   
}

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream input("input.txt");
  ofstream output("output.txt");

  string line;
  while (getline(input, line)) {
    output << line << endl;
  }

  return 0;
}
*/