# include <iostream>
# include <vector>
# include <string>
# include <iomanip>
# include <algorithm>
# include <locale>
using namespace std;
    
bool myfunction (const string& i,const string& j) {
    int sizeshe = i.size();
    if (i.size() > j.size()) {
        sizeshe = j.size();
    }
    for (int item = 0; item < sizeshe; ++item) {
        if (tolower(i[item]) < tolower(j[item])) {
            return true;
        }
        if (tolower(i[item]) > tolower(j[item])) {
            return false;
        }
    }
    if (i.size() < j.size()) {
        return true;
    }

    return false;    
}

int main() {
    int n;
    vector<string> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string ent;
        cin >> ent;
        v.push_back(ent);
    }

    sort(begin(v), end(v), myfunction);

    for (const string& per: v) {
        cout << per << " ";
    }
    cout << endl;
    return 0;
}