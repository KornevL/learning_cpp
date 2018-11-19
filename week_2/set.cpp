# include <iostream>
# include <string>
# include <vector> 
# include <set>
using namespace std;

void PrintSet (const set<string>& s) {
    for(auto x: s) {
        cout << x << endl;
    }
}
int main () {
    set<string> famous_persons;
    famous_persons.insert("Gorishniy");
    famous_persons.insert("Kornev");
    famous_persons.insert("Orlov");
    famous_persons.erase("Orlovs");
    PrintSet(famous_persons);
    cout << famous_persons.count("Kornev") << endl;

    vector<string> vec = {"a", "b", "c", "d", "a"};
    set<string> alf(begin(vec), end(vec));
    return 0;
}