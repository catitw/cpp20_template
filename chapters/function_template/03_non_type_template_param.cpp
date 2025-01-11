#include <cstddef>
#include <iostream>

template <std::size_t N> void f() { std::cout << N << '\n'; }

int main() { f<100>(); }
