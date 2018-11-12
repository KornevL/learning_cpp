# include <iostream>
using namespace std;

/*
int Factorial(int x) {
  if (x <= 1) {
    return 1;
  } else {
    return x * Factorial(x - 1);  // вычисляем факториал от x-1 и умножаем на x
  }
}
*/

int Factorial (int x) {
    int num = 1;
    while (x > 1) {
        num *= x;
        x--;
    }
    return num;
}
/*

int main () {
    int x;
    cin >> x;
    cout << Factorial(x);
    return 0;
}
*/
