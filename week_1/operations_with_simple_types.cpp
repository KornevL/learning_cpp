# include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 3;
    int xx = 5;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "(x + y) / (x - y) = " << (x + y) / (x - y) << endl;
    cout << "x and y is ";
    if (x == y) {
        cout << "equal" << endl;
    } else {
        cout << "not equal" << endl;
    }
    if (x != xx) {
        cout << " x and 5 not equal" << endl;
    } else {
        cout << "x and 5 equal" << endl;
    }
    return 0;
}