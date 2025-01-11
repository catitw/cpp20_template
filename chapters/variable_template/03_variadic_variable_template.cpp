#include <cstddef>
#include <iostream>

template <std::size_t... value> constexpr std::size_t array[]{value...};

int main() {
  for (const auto &i : array<1, 3, 4, 5>) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  std::cout << &array<1, 2> << '\n'; // 0x55c7d5f48060
  std::cout << &array<1, 3> << '\n'; // 0x55c7d5f48070
  std::cout << &array<1, 2> << '\n'; // 0x55c7d5f48060
}