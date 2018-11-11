# include <iostream>
# include <vector>
using namespace std;

int main() {
    int x, two;
    vector <int> vec, cev;
    cin >> x;
    // if x = 0  -->  print "0"
    if (x == 0) {
        cout << 0;
    }
    // if x > 0  -->  translate into a binary number system
    while ( x != 0) {
        two = x % 2;
        vec.push_back(two);
        x /= 2;
    }
    // in vec binary number is written back to front
    int razmer = vec.size();
    // binary output with deploing
    for(int i = 1; i <= razmer; i++) {
        cout << vec[razmer - i];
    }
    
    return 0;
}