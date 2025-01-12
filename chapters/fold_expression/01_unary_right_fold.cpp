#include <iostream>

template <typename... Args> // newline
void print(const Args &...args) {

  // (E 运算符 ...)
  // E: `(std::cout << args << ' ')`
  // 运算符: `,`
  // ...
  ((std::cout << args << ' '), ...);
}

/* First instantiated from: insights.cpp:8 */
#ifdef INSIGHTS_USE_TEMPLATE
template <>
void print<char[4], int, double>(const char (&__args0)[4], const int &__args1,
                                 const double &__args2) {
  (std::operator<<(std::operator<<(std::cout, __args0), ' ')),
      ((std::operator<<(std::cout.operator<<(__args1), ' ')),
       (std::operator<<(std::cout.operator<<(__args2), ' ')));
}
#endif

int main() {
  // print: "abc 1 2.1 "
  print("abc", 1, 2.1);
}