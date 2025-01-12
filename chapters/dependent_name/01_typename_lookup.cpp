#include <iostream>
#include <vector>

// -----------------------------     case0     ---------------------------------
// 典型的错误，实际上可能不会将`T::type`视作是一个类型

// template <typename T> // newline
// const T::type f(const T &) {
//   return 1;
// }

// struct X {
//   using type = int;
// };

// -----------------------------     case1     ---------------------------------
// 在模板（类模板和函数模板）定义中，某些构造的含义可以在不同的实例化间有所不同。
// 特别是，类型和表达式可能会取决于类型模板形参的类型和非类型模板形参的值。
// 除非使用关键词 typename 或它已经被设立为类型名（例如用 typedef
// 声明或通过用作基类名）。 此处，标识符 `T::type` 即为 dependent_name.

template <typename T> // newline
const typename T::type f(const T &) {
  return 1;
}

struct X {
  using type = int;
};

// -----------------------------     case2     ---------------------------------
int p = 1;

template <typename T> void foo(const std::vector<T> &v) {
  // std::vector<T>::const_iterator 是待决名，
  [[maybe_unused]] typename std::vector<T>::const_iterator it = v.begin();

  // 下列内容因为没有 'typename' 而会被解析成
  // 类型待决的成员变量 'const_iterator' 和某变量 'p' 的乘法。
  // 因为在此处有一个可见的全局 'p'，所以此模板定义能编译。
  // std::vector<T>::const_iterator *p;

  typedef typename std::vector<T>::const_iterator iter_t;
  [[maybe_unused]] iter_t *p2; // iter_t 是待决名，但已知它是类型名
}

void test_case2() {
  std::vector<int> v;
  foo(v);
}

int main() {
  std::cout << f(X{}) << '\n';
  ;
}