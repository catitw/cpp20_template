#include "header.h"
#include <iostream>

template <typename T> void Case1<T>::foo() {
  std::cout << "Case1<T>::foo()" << '\n';
};

template <typename T> void Case2<T>::foo() {
  std::cout << "Case2<T>::foo()" << '\n';
};

// explicit instante
template void Case2<int>::foo();
