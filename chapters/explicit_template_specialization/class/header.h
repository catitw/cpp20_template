#pragma once

#include <iostream>

template <typename T> struct InlineClass {
  void f() { std::cout << "InlineClass<T>::f()" << '\n'; }
};

template <typename T> struct ExternFuncClass {
  void f();
};

// 只有在`impl.cpp`中由于进行了显式实例化，才在该翻译单元具有定义
extern template struct ExternFuncClass<int>;