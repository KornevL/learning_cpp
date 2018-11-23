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
    Person (const string& name, const string& famil, int year) {
        first[year] = name;
        last[year] = famil;
        yeah = year;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year > yeah)
        first[year]= first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year > yeah)
        last[year]= last_name;
    }
    string GetFullName(int year) const {
        string pull;

        string first_n = GetFN(first, year);

        string second_n = GetFN(last, year);

        if (first_n.empty() && second_n.empty()) {
            pull = "No person";
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

    string GetFullNameWithHistory (int year) const{
        string pull;
        
        string first_n = GetFN(first, year);

        string second_n = GetFN(last, year);

        string first_set = GetFNWH(first, year);

        string last_set = GetFNWH(last, year);

        if (first_n.empty() && second_n.empty()) {
            pull = "No person";
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
    int yeah;
};

// При получении на вход года, который меньше года рождения:

// методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
// Кроме того, необходимо объявить константными все методы, которые по сути ими являются.
/*
int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  person.ChangeFirstName(1900, "A111ppolinaria");
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
*/
// OUTOUT:

// No person
// Polina Sergeeva
// Appolinaria (Polina) Sergeeva
// Appolinaria (Polina) Ivanova (Sergeeva)
