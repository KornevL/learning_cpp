# include <iostream>
# include <string>
# include <vector>
# include <algorithm> 
using namespace std;

int main() {
    vector<int> nums = {1, 5, 4, 3, 7, 8, -9};
    for (int c : nums) {
        cout << c << ", ";
    };
    cout << endl;
    string s = "abcdefghjklmnopqrstuvwxyz";
    for (auto c : s) {
        cout << c << ", ";
    };
    cout << endl;

    int quantity = 0;
    vector<int> numbers = {1, 3, 5, 4, 3, 5, 6, 7, 5, 4, 8, 2, 6, 5};
    for (auto x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    for (auto c : numbers) {
        if (c == 5) {
            quantity += 1;
        }
    }
    cout << "quantity of nember 5 is " << quantity << " in my vector" << endl;

// work whis algorithms
    int quantity_algorithm = 0;
    quantity_algorithm = count(begin(numbers), end(numbers), 5);
    cout << "quantity of nember 5 is " << quantity_algorithm << " in my vector" << endl;

    sort(begin(numbers), end(numbers));
    for (auto x : numbers) {
        cout << x << " ";
    }

    return 0;
}