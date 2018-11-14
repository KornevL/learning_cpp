# include <iostream>
# include <string>
# include <vector>

using namespace std;


/*
// определяет, является ли строка s палиндромом
bool IsPalindrom(string s) {
  
  // переберём все символы s[i] из первой половины строки
  for (size_t i = 0; i < s.size() / 2; ++i) {
    // s[s.size() - i - 1] — символ, симметричный символу s[i]
    if (s[i] != s[s.size() - i - 1]) {
      return false;  // если они не совпадают, строка точно не палиндром
    }
  }
  
  // если все пары символов совпадают, строка — палиндром
  return true;
}

vector<string> PalindromFilter(vector<string> words, int min_length) {
  vector<string> result;
  // перебираем все элементы вектора words
  for (auto s : words) {
    // если требуеые условия выполняются, добавляем s к ответу
    if (s.size() >= min_length && IsPalindrom(s)) {
      result.push_back(s);
    }
  }
  return result;
}
*/


vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> ansver;
    for (string word: words) {
        if (word.size() >= minLength) {
            int value = 1;
            for (int i = 0; i < word.size() / 2; i++) {
                if ( word[i] != word[word.size() - 1 - i])
                    value = 0;
            }
            if (value == 1)
                ansver.push_back(word);
        }
    }
    return ansver;
}
/*
int main () {
    vector<string> sss = {"123", "1234", "2332", "1234554321", "345345345345", "12211221"};
    int asd = 4;
    vector<string> ss;
    ss = PalindromFilter(sss, asd);
    for (auto w: ss)
        cout << w << "---";
    return 0;
}
*/
