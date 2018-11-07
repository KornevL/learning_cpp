# include <iostream>
# include <string>
# include <vector>
# include <map>
using namespace std;

int main() {
    int x = -123;
    double pi = 3.14;
    bool logical_value = true;
    char symbol = 'Z';
    cout << x << endl; // prints x type integer
    cout << pi << endl; // '<< endl' is line break
    cout << logical_value << endl;
    cout << symbol << endl;
    
    string hw = "Hello, World!"; // include library <string>

    vector<int> nums = {1, 3, 5, 7}; // include library <vector>
    cout << "My vector size is " << nums.size() << endl;

    map<string, int> name_to_value; // include library <map> -- dictionary
    name_to_value["one"] = 1;
    name_to_value["two"] = 2;
    cout << "two is " << name_to_value["two"] << endl;
    return 0;
}
