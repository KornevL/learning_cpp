#include <iostream>
#include <vector>
using namespace std;

/*
Даны значения температуры, наблюдавшиеся в течение N
подряд идущих дней. Найдите номера дней (в нумерации с нуля)
со значением температуры выше среднего арифметического за все N дней.
Гарантируется, что среднее арифметическое значений
температуры является целым числом.

Формат ввода
Вводится число N, затем N неотрицательных целых чисел —
значения температуры в 0-й, 1-й, ... (N−1)-й день.

Формат вывода
Первое число K — количество дней, значение температуры в
которых выше среднего арифметического. Затем K целых чисел — номера этих дней.
*/

int main() {
    int days, average_temperature = 0;
    cin >> days;
    vector<int> temprecha(days);
    vector<int> truetemprecha;
    for (auto i = 0; i < days; ++i) {
        cin >> temprecha[i];
        average_temperature += temprecha[i];
    }
    average_temperature /= days;

    for (auto i = 0; i < days; ++i) {
        if (temprecha[i] > average_temperature)
            truetemprecha.push_back(i);
    }
    cout << truetemprecha.size() << endl;
    for (auto i: truetemprecha) {
        cout << i << " ";
    }
    return 0;
}
