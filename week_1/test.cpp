# include <iostream>
# include <string>
using namespace std;

int main() {
    int number = 78;
    int isequal;

    do {
        cout << "Guess the number: ";
        cin >> isequal;
    } while (isequal != number);
    cout << "Congrats! You're right!" << endl;
    return 0;
}
