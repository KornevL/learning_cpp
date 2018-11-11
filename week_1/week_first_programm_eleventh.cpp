# include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    if ( a < b ) {
        c = a;
        a = b;
        b = c;
    }
    while (b != 0) {
        c = a;
        a = b;
        b = c % b;
    }
    cout << a;
    return 0;
}