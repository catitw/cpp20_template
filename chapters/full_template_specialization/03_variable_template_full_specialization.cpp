
#include <iostream>

template <typename T> constexpr const char *type_name = "??";

template <> constexpr const char *type_name<void> = "void";

template <> constexpr const char *type_name<int> = "int";

int main() {
  std::cout << type_name<double> << '\n'; // ??
  std::cout << type_name<bool> << '\n';   // ??

  std::cout << type_name<void> << '\n'; // void
  std::cout << type_name<int> << '\n';  // int

  // every address not same
  std::cout << &type_name<double> << '\n'; // 0x55d57a097db0
  std::cout << &type_name<bool> << '\n';   // 0x55d57a097db8
  std::cout << &type_name<void> << '\n';   // 0x55d57a097da0
  std::cout << &type_name<int> << '\n';    // 0x55d57a097da8
}