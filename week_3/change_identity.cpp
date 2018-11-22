# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <map>
using namespace std;

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
        int trig1 = 0;
        int trig2 = 0;
        string first_n, second_n;

        for (const auto& m: first) {
            if (m.first <= year) {
                first_n = m.second;
                trig1 = 1;
            }
        }

        for (const auto& m: last) {
            if (m.first <= year) {
                second_n = m.second;
                trig2 = 1;
            }
        }
         
        if (trig1 == 0 && trig2 == 0) {
            pull = "Incognito";
            return pull;
        } else if (trig1 == 0) {
            pull = second_n + " with unknown first name";
            return pull;
        } else if (trig2 == 0){
            pull = first_n + " with unknown last name";
            return pull;
        } else {
            pull = first_n + " " + second_n;
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
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
*/
// OUTPUT:
// Incognito
// Polina with unknown last name
// Polina Sergeeva
// Polina Sergeeva
// Appolinaria Sergeeva
// Polina Volkova
// Appolinaria Volkova

