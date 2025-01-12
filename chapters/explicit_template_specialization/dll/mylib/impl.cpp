#include "header.h"
#include <format>
#include <iostream>
#include <string>

template <typename T> void f(T t) {
  std::cout << std::format("void f({})", t) << '\n';
}

#ifdef _MSC_VER
template __declspec(dllexport) void f<int>(int);
template __declspec(dllexport) void f<std::string>(std::string);
#else
template void f<int>(int);
template void f<std::string>(std::string);
#endif

template <typename T> void X<T>::f() { std::cout << "void X<T>::f()" << '\n'; }

// 显式实例化
template struct X<int>;
template struct X<std::string>;