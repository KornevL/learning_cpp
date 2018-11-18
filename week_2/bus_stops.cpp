# include <iostream>
# include <string>
# include <map>
# include <vector>
using namespace std;

int main() {
    int q;
    string enter;
    map<string,vector<string>> buses;
    map<string,vector<string>> stops;
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> enter;

        if (enter == "NEW_BUS") {
            string bus;
            cin >> bus;
            buses[bus];
            int stop_count;
            cin >> stop_count;
            for (int i=0; i < stop_count; ++i) {
                string stop;
                cin >> stop;
                stops[stop].push_back(bus);
                buses[bus].push_back(stop);
            }
        }

        if (enter == "ALL_BUSES") {
            if (buses.size() != 0) {
                for (const auto& bus: buses) {
                    cout << "Bus " << bus.first << ": ";
                    for (const auto& stop: bus.second) {
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            } else {
                cout << "No buses" << endl;
            }
        }

        if (enter == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stops.count(stop) == 1) {
                for(const auto& item: stops[stop]) {
                    cout << item << " ";
                }
            } else {
                cout << "No stop";
            }
            cout << endl;
        }

        if (enter == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses.count(bus) == 1) {
                for(const auto& stop: buses[bus]) {
                    cout << "Stop " << stop << ": ";
                    if (stops[stop].size() != 1) {
                        for(const auto& item: stops[stop]) {
                            if (item != bus) {
                                cout << item << " ";
                            }
                        }
                        cout << endl;
                    } else {
                        cout << "no interchange" << endl; 
                    }
                }
            } else {
                cout << "No bus" << endl;
            }
        }
  
    }
    return 0;
}