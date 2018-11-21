# include <iostream>
# include <string>

using namespace std;

int main() {
    int x;
    cin >> x;
    string s = (x % 2 == 0) ? "even" : "odd";
    cout << x << " is " << s << endl;
    return 0;
}