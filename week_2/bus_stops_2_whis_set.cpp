# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <set>
using namespace std;

int main() {
    int q, w;
    int e = 0;
    string enter;
    map<set<string>, int> buses;
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> w;
        set<string> stop;
        for (int j = 0; j < w; ++j){
            string st;
            cin >> st;
            stop.insert(st);
        }
        if (buses.count(stop) == 1) {
            cout << "Already exists for " << buses[stop] << endl;
        } else {
            ++e;
            cout << "New bus " << e << endl;
            buses[stop] = e;
        }
    }
    return 0;
}