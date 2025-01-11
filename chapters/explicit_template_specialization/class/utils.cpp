#include "utils.h"
#include "header.h"
#include <iostream>

void util_func() {
  std::cout << "void util_func() begin:" << '\n';

  InlineClass<int>{}.f();
  ExternFuncClass<int>{}.f();

  std::cout << "void util_func() end:" << '\n';
}
