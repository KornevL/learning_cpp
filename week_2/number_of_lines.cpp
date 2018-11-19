# include <iostream>
# include <string>
# include <set>
using namespace std;

int main () {
    int q;
    cin >> q;
    set<string> set_strings;
    for(int i = 0; i < q; ++i) {
        string word;
        cin >> word;
        set_strings.insert(word);
    }
    cout << set_strings.size() << endl;
    return 0;
}