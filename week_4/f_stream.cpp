#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    // if (input.is_open()) {
    if (input) {
        while (getline(input, line)) {
            cout << line << endl;
            input >> line;
            input.ignore();
        }
    } else {
        cout << "error: file is not opened! \n";
    }

    ofstream output("output.txt", ios::app);
    output << "KY-KY!! \n";


    cout << fixed << setprecision(2);
    cout << setw(10) << setfill(')'); 
    cout << left;
    double qwe;
    qwe = 0.419;
    cout << qwe << endl;



    return 0;
}