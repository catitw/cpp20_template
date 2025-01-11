#include "signature.h"
#include <iostream>

// 万能引用
// 如果 t 接受左值表达式，则 T 推导为左值引用;
// 如果 t 接受右值表达式，则 T 推导为右值引用;
template <typename T> void f(T &&t) {
  PRINT_FUNC_SIGNATURE();

  // 判断是左值还是右值
  if (std::is_lvalue_reference<decltype(t)>::value) {
    std::cout << "Value category: lvalue\n";
  } else {
    std::cout << "Value category: rvalue\n";
  }
}

int main() {
  int a = 1;

  // 引用折叠： 右值引用的右值引用折叠为右值引用，其余组合均为左值引用.

  f(a); // 表达式`a`为左值, T 的类型为 int&, T&& 推导为 int&
  // Function signature: void f(T&&) [with T = int&]
  // Value category: lvalue

  f(1); // 表达式`1`为右值, T 的类型为 int&&, T&& 推导为 int&&
  // Function signature: void f(T&&) [with T = int]
  // Value category: rvalue
}
