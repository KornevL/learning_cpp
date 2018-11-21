# include <iostream>
# include <string>
# include <vector>
using namespace std;
struct pents {
    // private: 
    int dogs;
    int cats;
    int rats;
    int snakes;
};

struct Person {
    string name;
    string surname;
    int age;
    pents his_pents;
};

void PrintPents( const Person& pers) {
    cout << "His have: ";
    cout << pers.his_pents.dogs <<" dogs,";
    cout << pers.his_pents.cats <<" cats,";
    cout << pers.his_pents.rats <<" rats,";
    cout << pers.his_pents.snakes <<" snakes. \n";
}

void PrintMen( const Person& pers) {
    cout << "Men: \n";
    cout << "Name: ";
    cout << pers.name << "\n";
    cout << "Surname: ";
    cout << pers.surname << "\n";
    cout << "Age: ";
    cout << pers.age << "\n";
    PrintPents(pers);
}

void PrintPeople (const vector<Person>& peoples) {
    for (const auto& people: peoples) {
        PrintMen(people);
    }
}

int main() {
    vector<Person> staff;
    staff.push_back({"Ivan", "Ivanov", 25, {1, 0, 1, 0}});
    staff.push_back({"Abraham", "Izmailov", 29, {1, 1, 1, 1}});
    PrintPeople(staff);
    return 0;
}