# include <iostream>
# include <vector>
# include <string>
# include <iomanip>
# include <algorithm> 
using namespace std;
    
bool myfunction (int i,int j) {
    return (abs(i)<abs(j)); 
    }

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int ent;
        cin >> ent;
        v.push_back(ent);
    }

    sort(begin(v), end(v), myfunction);
    
    // sort(begin(v), end(v),
    //    // функция, сравнивающая abs(l) и abs(r) — модули чисел l и r
    //    [](int l, int r) {
    //      return abs(l) > abs(r);
    //    }
    // );

    for (const auto& per: v) {
        cout << per << " ";
    }
    cout << endl;
    return 0;
}