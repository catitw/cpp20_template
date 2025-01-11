#pragma once
#include <iostream>

template <typename T> void internal_link_func(T t) {
  std::cout << "internal_link_func: " << t << '\n';
}

template <typename T> void explicit_func(T t);

extern template void explicit_func<>(int);
