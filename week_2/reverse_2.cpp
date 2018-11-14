# include <iostream>
# include <string>
# include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> rev = v;
    int a;
    for (int i = 0; i < rev.size() / 2; i++) {
        a = rev[i];
        rev[i] = rev[rev.size() - 1 - i];
        rev[rev.size() - 1 - i] = a;
    }
    return rev;
}

/*
Реализуйте функцию vector<int> Reversed(const vector<int>& v),
возвращающую копию вектора v, в которой числа переставлены в
обратном порядке.
*/