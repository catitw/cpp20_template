#include "signature.h"
#include <cstddef>
#include <iostream>

template <std::size_t N> void f() {
  PRINT_FUNC_SIGNATURE();
  std::cout << N << '\n';
}

int main() { f<100>(); }
