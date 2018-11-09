# include <iostream>
# include <cmath>

using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    float diskr = b * b - 4 * a * c;
    if (a != 0) {
        if (diskr >= 0) {
            cout << (-b + sqrt(diskr)) / (2 * a);
            if (diskr > 0) {
                cout << " " << (-b - sqrt(diskr)) / (2 * a);
            }
        }
    } else if (b != 0) {
        cout << -(c / b);
    }

    return 0;
}
