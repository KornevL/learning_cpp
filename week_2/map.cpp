# include <iostream>
# include <map>
# include <string>
# include <vector> 
using namespace std;

void PrintMapINT (const map<int, string>& e) {
    cout << "size = " << e.size() << endl;
    for(const auto& m: e) {
        cout << m.first << ": " << m.second << endl;
    }
}

void PrintMapSTR (const map<string,int>& counters) {
    cout << "size = " << counters.size() << endl;
    for(const auto& m: counters) {
        cout << m.first << ": " << m.second << endl;
        }
}

int main () {
    map<int, string> events ={{2013,"Lev's first day in university"}};
    events[1995] = "Lev Kornev's birth";
    events[1965] = "Alexander Kornev's birth";
    events[2000] = "Lev's first class in school";
    PrintMapINT(events);

    cout << events[2013] << endl;

    events.erase(2013);
    PrintMapINT(events);
    
    cout << "!!!!!!!NICE GAME!!!!!!!" << endl;

    vector<string> words={"one", "three", "two", "three", "two", "three"};
    map<string,int> counters;
    for(const auto& w: words) {
        ++counters[w];
    }
    PrintMapSTR(counters);
    return 0;
}