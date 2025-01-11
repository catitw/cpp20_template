#include "header.h"
#include <iostream>

template <typename T> void f(T) {
  std::cout << "template <typename T> void f(T)" << '\n';
}

template void f<int>(int);
