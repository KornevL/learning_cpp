# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;


class Route { 
    public:
    string GetSource() {
        return source; 
    }
    string GetDestination() {
        return destination;
    }
    int GetLength() {
        return length;
    }
    void SetSource(const string& new_source) {
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }
    private:
    void UpdateLength() {
        length = tolower(source[0]) + tolower(destination[0]);
        // Этот метод дается от балды, чтоб менять расстояние между городамиc
    }
    string source;
    string destination;
    int length;
};


int main() {
    Route route;
    string a, b;
    cin >> a >> b;
    route.SetSource(a);
    route.SetDestination(b);
    cout << "Route from " <<
        route.GetSource() << " to " <<
        route.GetDestination() << " is " <<
        route.GetLength() << " meters long";
    return 0;
}