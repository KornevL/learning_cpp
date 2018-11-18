# include <iostream>
# include <string>
# include <map>
using namespace std;

int main() {
    int q;
    string enter;
    map<string,string> capitals;
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> enter;

        if (enter == "ABOUT") {
            string country;
            cin >> country;
            if (capitals.count(country) == 1) {
                cout << "Country " << country << " has capital " << capitals[country] << endl;
            } else {
                cout << "Country " << country << " doesn't exist" << endl;
            }
        }

        if (enter == "DUMP") {
            if (capitals.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                // for (const auto& [country, capital]: capitals) {
                //     cout << country << "/" << capital << " ";
                // }
                 for (const auto& item: capitals) {
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        }
        if (enter == "CHANGE_CAPITAL") {
            string country ,new_capital;
            cin >> country >> new_capital;
            if (capitals.count(country) == 0) {
                cout << "Introduce new country " << country 
                << " with capital " << new_capital << endl;
                capitals[country] = new_capital; 
            } else { if(capitals[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else { 
                cout << "Country " << country << " has changed its capital from " 
                << capitals[country] << " to " << new_capital << endl;
                capitals[country] = new_capital;
            }
            }
        }
        if (enter == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            
            if (capitals.count(old_country_name) == 0 ||
                capitals.count(new_country_name) == 1 ||
                old_country_name == new_country_name) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital "
                << capitals[old_country_name]
                << " has been renamed to " << new_country_name << endl;
                capitals[new_country_name] = capitals[old_country_name];
                capitals.erase(old_country_name);
            }
        }   
    }
    return 0;
}