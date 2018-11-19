# include <iostream>
# include <vector>
# include <map>
# include <set>

using namespace std;

// Напишите функцию BuildMapValuesSet, принимающую на вход
// словарь map<int, string> и возвращающую множество значений этого словаря.

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> set_obtained_from_map;
    for (auto w: m) {
        set_obtained_from_map.insert(w.second);
    }
    return set_obtained_from_map;
}