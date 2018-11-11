# include <iostream>
# include <string>
using namespace std;

int main() {
    
    string word;
    cin >> word;

    char f = 'f';

    int i = 0;
    int counter = -2;
    for (auto l : word) {
        if (l == f) {
            counter += 1;
            if (counter == 0) {
                cout << i ;
                break;
            }
        }
        i++;
    }
    if (counter != 0)
        cout << counter;
    return 0;
}