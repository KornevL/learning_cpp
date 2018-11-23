# include <iostream>
# include <vector>
using namespace std;

// struct Incognizable {
//   int x = 0;
//   int y = 0;
// };

class Incognizable {
    public:
    Incognizable () {}
    Incognizable (const int& a, const int& b = 0) {
        vec.push_back(a);
        vec.push_back(b);
    }
    private:
    vector<int> vec;
};

// int main() {
//   Incognizable a;
//   Incognizable b = {};
//   Incognizable c = {0};
//   Incognizable d = {0, 1};
//   return 0;
// }
