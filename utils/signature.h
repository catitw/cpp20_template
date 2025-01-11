#pragma once

#include <iostream>

#define PRINT_FUNC_SIGNATURE()                                                 \
  {                                                                            \
    std::cout << __PRETTY_FUNCTION__ << '\n';                                  \
  }

std::string demangle(const char *mangled);

template <typename T> void print_typename(T x) {
  std::cout << demangle(typeid(x).name()) << '\n';
}