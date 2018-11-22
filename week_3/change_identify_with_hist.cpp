# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <map>
using namespace std;

string GetFN (const map<int,string>& vec, int y) {
    string her_name;
    for (const auto& m: vec) {
        if (m.first <= y) {
            her_name = m.second;
        } else {
            break;
        }
    }
    return her_name;
}

string GetFNWH (const map<int,string>& vec, int y) {
    vector <string> set_hist;
    string her_hist, trig;
    for (const auto& m: vec) {
        if (m.first <= y && m.second != trig) {
            
            // cout << "TRIG ->" << trig << endl;
            // cout << "in vec ->" <<m.second << endl;
            set_hist.push_back(m.second);
            trig = m.second;
        }
    }
    if (!set_hist.empty()) {
        set_hist.resize(set_hist.size() - 1);
    }

    string a;
    for (int i = 0; i < set_hist.size() / 2; i++) {
        a = set_hist[i];
        set_hist[i] = set_hist[set_hist.size() - 1 - i];
        set_hist[set_hist.size() - 1 - i] = a;
    }

    for (auto h: set_hist) {
        her_hist += h + ", ";
    }
    if (!her_hist.empty()) {
        her_hist.resize(her_hist.size() - 2);
        her_hist = " (" + her_hist + ")";
    }
    return her_hist;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first[year]= first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last[year]= last_name;
    }
    string GetFullName(int year) {
        string pull;

        string first_n = GetFN(first, year);

        string second_n = GetFN(last, year);

        if (first_n.empty() && second_n.empty()) {
            pull = "Incognito";
            return pull;
        } else if (first_n.empty()) {
            pull = second_n + " with unknown first name";
            return pull;
        } else if (second_n.empty()){
            pull = first_n + " with unknown last name";
            return pull;
        } else {
            pull = first_n + " " + second_n;
            return pull;
        }
    }

    string GetFullNameWithHistory(int year) {
        string pull;
        
        string first_n = GetFN(first, year);

        string second_n = GetFN(last, year);

        string first_set = GetFNWH(first, year);

        string last_set = GetFNWH(last, year);

        if (first_n.empty() && second_n.empty()) {
            pull = "Incognito";
            return pull;
        } else if (first_n.empty()) {
            pull = second_n + last_set + " with unknown first name";
            return pull;
        } else if (second_n.empty()){
            pull = first_n + first_set + " with unknown last name";
            return pull;
        } else {
            pull = first_n + first_set + " " + second_n + last_set;
            return pull;
        }
    }
private:
    
    map<int,string> first;
    map<int,string> last;

};

/*
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
*/

// OUTPUT:

// Incognito
// Polina with unknown last name
// Polina Sergeeva
// Polina Sergeeva
// Appolinaria (Polina) Sergeeva
// Polina Volkova (Sergeeva)
// Appolinaria (Polina) Volkova (Sergeeva)
// Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
// Pauline (Polina) with unknown last name
// Sergeeva with unknown first name
// Pauline (Polina) Sergeeva
// Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
