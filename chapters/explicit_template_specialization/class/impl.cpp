#include "header.h"

template <typename T> void ExternFuncClass<T>::f() {
  std::cout << "ExternFuncClass<T>::f()" << '\n';
};

// 显式实例化
// 
// 方式一: 只显式实例化模板类的成员函数
// template void ExternFuncClass<int>::f();
//
// 方式二: 直接显示实例化成员类
template struct ExternFuncClass<int>;