#include "signature.h"
#include <iostream>

template <typename T> void test(T) {
  PRINT_FUNC_SIGNATURE();
  std::cout << "template func" << '\n';
}

void test(int) {
  PRINT_FUNC_SIGNATURE();
  std::cout << "int" << '\n';
}

int main() {
  test(1);

  test("1");
  test(1.2);
}
