#include <iostream>

template <typename... Args> // newline
void print(const Args &...args) {

  // (I 运算符 ... 运算符 E)
  // I: `std::cout`
  // 运算符 ... 运算符: `<< ... <<`
  // E: args
  (std::cout << ... << args) << '\n';
}

/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template <>
void print<char[4], int, double>(const char (&__args0)[4], const int &__args1,
                                 const double &__args2) {
  std::operator<<(std::operator<<(std::cout, __args0)
                      .operator<<(__args1)
                      .operator<<(__args2),
                  '\n');
}
#endif

int main() {
  // print "abc12.1"
  print("abc", 1, 2.1);
  ;
}