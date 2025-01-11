#include "header.h"

void util_func() {
  std::cout << "void util_func() begin:" << '\n';
  f(10);
  internal_link_func(10);
  std::cout << "void util_func() end:" << '\n';
}
