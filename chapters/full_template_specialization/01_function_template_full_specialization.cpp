#include <iostream>
#include <type_traits>

template <typename T1, typename T2, typename R = std::common_type_t<T1, T2>>
auto f(const T1 &&a, const T2 &&b) -> R { // primary template
  return a + b;
}

// explicit specialization for [T1=double, T2=int, R=double]
template <> auto f(const double &&a, const int &&b) -> double { return a - b; }

// same way, but explicitly provide types.
template <>
auto f<int, double, double>(const int &&a, const double &&b) -> double {
  return a * b;
}

int main() {
  std::cout << f(1, 2) << '\n';   // 3
  std::cout << f(1.0, 2) << '\n'; // -1
}
