#include <iostream>

template <typename T = int> constexpr T v{};

int main() {
  // auto x = v;  // error: variable template 'v' requires template arguments
  auto x = v<>;

  std::cout << x << '\n';
}