#pragma once

#include <string>

template <typename T> void f(T t);

extern template void f<int>(int);
extern template void f<std::string>(std::string);

#ifdef _MSC_VER
template __declspec(dllexport)<typename T> struct X {
  void f();
};
#else
template <typename T> struct X {
  void f();
};
#endif

extern template struct X<int>;
extern template struct X<std::string>;
