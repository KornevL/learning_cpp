# include <iostream>
# include <map>
# include <string>

using namespace std;

map<char, int> BuildCharCounters (const string& word) {
    map<char, int> anag;
    for (auto liter: word) {
        ++anag[liter];
    }
    return anag;
}

int main () {
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        string a,b;
        cin >> a >> b;
        if (BuildCharCounters(a) == BuildCharCounters(b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}