# include <iostream>
# include <string>
# include <vector>
using namespace std;

struct Person {
    string name;
    string surname;
    int age;
};

int main() {
    vector<Person> staff;
    staff.push_back({"Ivan", "Ivanov", 25});
    staff.push_back({"Abraham", "Izmailov", 29});

    cout << staff[0].name << endl;
    return 0;
}