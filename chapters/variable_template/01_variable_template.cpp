#include <iostream>

template <typename T> T v; // defintion

void print(auto v) { std::cout << v << '\n'; }

int main() {
  ::print(v<int>); // 0

  {
    v<int> = 20;
    ::print(v<int>); // 20
  }

  ::print(v<int>); // 20

  print(&v<int>);    // 0x55d94bcf4154
  print(&v<double>); // 0x55d94bcf4158
}