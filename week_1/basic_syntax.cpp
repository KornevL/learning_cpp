#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 5;
    int sum = 0;
    int i = 1;
    // find summ of numbers [0, 5]
    cout << "find summ of numbers [0, 5]" << endl;
    while (i <= n) {
        sum += i;
        i += 1;
    }
    cout << sum << " <-- summ by while" << endl;
    /*
    Look, i do not redefinition of 'i'
    */
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    cout << sum << " <-- summ by for" << endl;
    return 0;
}