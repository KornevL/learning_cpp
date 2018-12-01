#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw 1;
        }
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
    if (arh.Numerator() == 0) {
            throw 2;
        }
    if (arh.Numerator() == 0) {
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
    int p, q;
    if (s >> p && s.ignore(1) && s >> q) {
        rat = { p, q };
    }
    return s;
}

int main() {
    try
    {
        Rational a, b;
        char ch;
        cin >> a >> ch >> b;
        if (ch == '+') cout << a + b;
        else if (ch == '-') cout << a - b;
        else if (ch == '*') cout << a * b;
        else cout << a / b;
    }
    catch (int f) { //ловим исключения по номеру
        if (f == 1) cout << "Invalid argument";
        else cout << "Division by zero";
    }
 
    return 0;
}