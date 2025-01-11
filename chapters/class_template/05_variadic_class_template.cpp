#include <iostream>
#include <tuple>

template <typename... Args> struct Pack {
  Pack(Args... args) : value{args...} {}

  std::tuple<Args...> value;
};

int main() {
  Pack p{1, "abc"};

  std::cout << std::get<0>(p.value) << '\n';    // print `1`
}