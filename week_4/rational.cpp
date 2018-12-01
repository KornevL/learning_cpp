#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        if ((numerator < 0 && denominator >0) || (denominator < 0 && numerator > 0)) {
            numerator = -abs(numerator);
            denominator = abs(denominator);
        } else {
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        if (numerator == 0) {
            num = 0;
            den = 1;
            if (denominator < 0) {
                den = -1;
            }
        }
        // +, - and 0 done;
                                    int c;
                                    int a = abs(numerator);
                                    int b = abs(denominator);
                                    if ( a < b ) {
                                        c = a;
                                        a = b;
                                        b = c;
                                    }
                                    while (b != 0) {
                                        c = a;
                                        a = b;
                                        b = c % b;
                                    }
        if (numerator != 0) {
            num = numerator / a;
            den = denominator / a;
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }

private:
    int num;
    int den;
};

Rational operator+(const Rational& alh, const Rational& arh) {
    Rational answer(alh.Numerator() * arh.Denominator() + arh.Numerator() * alh.Denominator(),
                    alh.Denominator() * arh.Denominator());
    return answer;
}

Rational operator-(const Rational& alh, const Rational& arh) {
    Rational answer(alh.Numerator() * arh.Denominator() - arh.Numerator() * alh.Denominator(),
                    alh.Denominator() * arh.Denominator());
    return answer;
}

Rational operator*(const Rational& alh, const Rational& arh) {
    Rational answer(alh.Numerator() * arh.Numerator(),
                    alh.Denominator() * arh.Denominator());
    return answer;
}

Rational operator/(const Rational& alh, const Rational& arh) {
    if (arh.Numerator() == 0 || alh.Denominator() == 0) {
        Rational qwe(0, 1);
        return qwe;
    }
    Rational answer(alh.Numerator() * arh.Denominator(),
                    alh.Denominator() * arh.Numerator());
    return answer;
}

bool operator==(const Rational& alh, const Rational& arh) {
    if (alh.Denominator() == arh.Denominator() && alh.Numerator() == arh.Numerator()) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const Rational& alh, const Rational& arh) {
    if ((alh - arh).Numerator() > 0) {
        return true;
    } else {
        return false;
    }
}

bool operator<(const Rational& alh, const Rational& arh) {
    if ((alh - arh).Numerator() < 0) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& s, const Rational& rat) {
    s << rat.Numerator() << '/' << rat.Denominator();
    return s;
}

istream& operator>>(istream& s, Rational& rat) {
    if (s.tellg() == -1) {
        return s;
    }
    int n, d;
    s >> n;
    s.ignore(1);
    s >> d;
    rat = {n,d};
    return s;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
/*
#include <iostream>

using namespace std;

// один из способов вычисления наибольшего общего делителя (НОД) — рекурсивный:
// вместо цикла функция будет вызывать себя же, но с другими аргументами
int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}

class Rational {
public:
  Rational() {  // дробь по умолчанию — 0/1
    numerator = 0;
    denominator = 1;
  }
  Rational(int new_numerator, int new_denominator) {
    const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
    // сократим дробь, разделив числитель и знаменатель на их НОД
    numerator = new_numerator / gcd;
    denominator = new_denominator / gcd;
    // знаменатель должен быть положительным
    if (denominator < 0) {
      denominator = -denominator;
      numerator = -numerator;
    }
  }

  int Numerator() const {
    return numerator;
  }

  int Denominator() const {
    return denominator;
  }

private:
  int numerator;
  int denominator;
};

// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator == (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
      lhs.Denominator() == rhs.Denominator();
}

// используем обычную формулу сложения дробей, основанную на приведении слагаемых к общему знаменателю
Rational operator + (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

// вычитание реализуем аналогично сложению
// дублирования кода можно было избежать, определив для класса Rational операцию унарного минуса: тогда разность lhs и rhs можно было бы вычислить           как lhs + (-rhs)
Rational operator - (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

// деление равносильно умножению на обратную («перевёрнутую») дробь
Rational operator / (const Rational& lhs, const Rational& rhs) {
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;
  is >> n >> c >> d;
  if (is && c == '/') {
    r = Rational(n, d);
  }
  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational& lhs, const Rational& rhs) {
  return (lhs - rhs).Numerator() < 0;
}
*/