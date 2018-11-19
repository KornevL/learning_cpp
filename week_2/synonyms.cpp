# include <iostream>
# include <string>
# include <vector> 
# include <set>
# include <map>
using namespace std;

int main() {
    int q;
    string enter, word, word2;
    map<string, set<string> > synonyms;
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> enter;

        if (enter == "ADD") {
            cin >> word >> word2;
            synonyms[word].insert(word2);
            synonyms[word2].insert(word);
        }

        if (enter == "COUNT") {
            cin >> word;
            cout << synonyms[word].size() << endl;
        }

        if (enter == "CHECK") {
            cin >> word >> word2;
            if (synonyms[word].count(word2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    
    }
    return 0;
}