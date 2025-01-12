#include <iostream>

// “代换失败不是错误” (Substitution Failure Is Not An Error)
// 当模板形参在替换成显式指定的类型或推导出的类型失败时，**从重载集中丢弃这个特化**，而非导致编译失败。

template <typename T, typename T2 = typename T::type> //
void f(T x) {
  std::cout << x << '\n';
}

template <typename T> //
void f(double) {
  std::cout << "void f(double)" << '\n';
  ;
}

int main() {
  // template argument deduction/substitution failed for `typename T2 = typename
  // T::type` error: no matching function for call to ‘f(int)’.
  // 第一个两泛型的模板代换失败，模板函数的特化被从重载集中丢弃，因此调用第二个函数模板
  f<int>(1);
}