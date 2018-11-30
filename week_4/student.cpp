#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct student {
    string first_name;
    string last_name;
    string num;
    string month;
    string year;
};


int main() {
    vector<student> bmstu;
    int n, m, dva;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        student vova;
        cin >> vova.first_name >> vova.last_name >> vova.month >> vova.num >> vova.year;
        bmstu.push_back(vova);
    }

    cin >> dva;
    for(int i = 0; i < dva; ++i) {
        string enter;
        cin >> enter >> m;
        if (enter == "name" && m > 0 && m <= n) {
            cout << bmstu[m-1].first_name << ' ' << bmstu[m-1].last_name << endl;
        } else {
        if (enter == "date" && m > 0 && m <= n) {
            cout << bmstu[m-1].num << '.' << bmstu[m-1].month << '.' <<bmstu[m-1].year << endl;
        } else {
            cout << "bad request" << endl;
        }
        }
    }
    return 0;
}