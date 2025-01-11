#include <iostream>

// -----------------------------     case1     ---------------------------------
template <typename T> const char *s = "?"; // 主模板

// 偏特化，对指针这一类类型
template <typename T> const char *s<T *> = "pointer";

// 偏特化，但是只是对 T[] 这一类类型，而不是数组类型，
// 因为 int[] 和 int[N] 不是一个类型
template <typename T> const char *s<T[]> = "array";

// -----------------------------     case2     ---------------------------------
template <typename T, typename T2> const char *ss = "??";
template <typename T2> const char *ss<int, T2> = "T == int";

int main() {
  std::cout << s<int> << '\n';           // ?
  std::cout << s<int *> << '\n';         // pointer
  std::cout << s<std::string *> << '\n'; // pointer
  std::cout << s<int[]> << '\n';         // array
  std::cout << s<double[]> << '\n';      // array
  std::cout << s<int[1]> << '\n';        // ?

  std::cout << ss<char, double> << '\n';     // ??
  std::cout << ss<int, double> << '\n';      // T == int
  std::cout << ss<int, std::string> << '\n'; // T == int
}