#include <iostream>
#include <type_traits>

template <typename T1, typename T2, typename R>
R max_v1(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

void max_v1_example() {
  // int x = max_v1(1, 2);  // error: couldn't infer template argument 'R'
}

// NOTE: 三目表达式的返回值类型是两个子表达式的公共类型。此处 true or
// false都不影响类型推导.
template <typename T1, typename T2,
          typename R = decltype(true ? T1{} : T2{}) // 不求值语境
          >
R max_v2(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

// C++11 后置返回类型
template <typename T1, typename T2>
auto max_v3(const T1 &a, const T2 &b)
    -> decltype(true ? a : b) // NOTE: 变量 a,b 此时存在可访问;
                              // 与上面的存在区别， a 或 b此时的类型是const T&，
                              // 取决于T;
                              // 而上面的写法，返回值类型是 T1{} or T2{},
                              // 不可能有CV限定符
{
  return a > b ? a : b;
}

// C++14, 返回值类型无CV限定
auto max_v4(const auto &a, const auto &b) { return a > b ? a : b; }

// C++14, 返回值类型具有CV限定
decltype(auto) max_v5(const auto &a, const auto &b) { return a > b ? a : b; }

void decltype_trick() {
  using T1 = decltype(true ? 1 : 1.2);
  using T2 = decltype(false ? 1 : 1.2);
  using T3 = decltype(true ? int{} : double{}); // 构造临时对象

  std::cout << (std::is_same_v<T1, T2> ? "true" : "false") << '\n'; // true
  std::cout << (std::is_same_v<T1, T3> ? "true" : "false") << '\n'; // true
}

int main() {
  decltype_trick();

  auto x = max_v2(1, 1.2);
  std::cout << x << '\n'; // 1.2

  max_v3(1, 1.2);
  max_v4(1, 1.2);
  max_v5(1, 1.2);
}