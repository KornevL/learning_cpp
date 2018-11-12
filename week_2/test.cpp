# include <iostream>
# include <vector>
# include <string>

using namespace std;

// объявление функции идёт с типа возвращаемого значения 

int Sum (int x, int y) {
    return x + y;
}


bool Contains(vector<string> words, string word) {
    for(auto s: words) {
        if (s == word)
            return true;
    }
    return false;
}


void PrintVector(string ask, vector<string> words) {
    if (ask != "0" && ask != "No" && ask != "no") {
        for (auto s: words) {
            cout << s << " ";
        }
    }
}


int main() {
    int x, y;
    string ask;
    cout << "Enter two numbers to search for their amount" << endl;
    cin >> x >> y;
    cout << Sum(x, y) << endl;

    vector<string> words = {"All", "you", "need", "is", "love"};
    cout << "Word search in vector" << endl;
    cout << Contains(words, "love");
    cout << endl << "Want to look at this vector?" << endl;
    cin >> ask;
    PrintVector(ask, words);
    cout << endl;
    return 0;
}
