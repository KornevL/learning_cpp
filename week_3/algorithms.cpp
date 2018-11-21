# include <iostream>
# include <vector>
# include <string>
# include <iomanip>
# include <algorithm> 
using namespace std;

bool trigger( int x) {
    if (x > 2) {
        return true;
    } else {
        return false;
    }
}
int main() {
    cout << min(2, 3) << endl;
    vector<int> v = {1, 3, 5, 2, 4};
    sort(begin(v), end(v));
    for (const auto& n: v) {
        cout << n << " ";
    } ;
    cout << endl;
    cout << count(begin(v), end(v), 2) << endl;
    int thr;
    cin >> thr;
    cout << count_if(begin(v), end(v), [thr](int x) {
    if (x > thr) {
        return true;
    } else {
        return false;
    }
    }) << endl;
    return 0;
}