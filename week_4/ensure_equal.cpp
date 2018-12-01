#include <iostream>
#include <string>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
    if (left != right) {
        string ex;
        ex =  left + " != " + right;                                // строчка с содержанием ошибки
        throw runtime_error(ex);                                    // так "бросается" ошибка (trow - ключевое слово)
    }
}
int main() {
  try {                                                             // блок проверки на ошибку
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {                                      // runtime_error& - ссылка на класс ошибок
    cout << e.what() << endl;                                       // запрашивает текст ошибки
  }
  return 0;
}