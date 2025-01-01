#include "template_utils.h"

template <typename T> void explicit_func(T t) {
  std::cout << "explicit_func: " << t << '\n';
}

template void explicit_func<int>(int);
