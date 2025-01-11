#include <ios>
#include <iostream>

template <typename, typename> struct is_same {
  static constexpr bool value = false;
};

template <typename Ty> struct is_same<Ty, Ty> {
  static constexpr bool value = true;
};

template <typename T1, typename T2>
constexpr bool is_same_v{::is_same<T1, T2>::value};

int main() {

  std::cout << std::boolalpha << ::is_same<int, void>::value << '\n'; // false
  std::cout << std::boolalpha << ::is_same<int, int>::value << '\n';  // true

  std::cout << std::boolalpha << ::is_same_v<int, void> << '\n'; // false
  std::cout << std::boolalpha << ::is_same_v<int, int> << '\n';  // true
}