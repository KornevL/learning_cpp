# include <iostream>
# include <string>
# include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    int a;
    for (int i = 0; i < v.size() / 2; i++) {
        a = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = a;
    }
}

/*
Реализуйте функцию void Reverse(vector<int>& v),
которая переставляет элементы вектора в обратном порядке.
*/