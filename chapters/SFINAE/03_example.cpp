#include <iostream>

// 该函数模板要求传入的对象必须是支持 operator+
template <typename T>
// 在返回类型中运用 SFINAE
auto add(const T &t1, const T &t2) -> decltype(t1 + t2) {
  std::puts("SFINAE +");
  return t1 + t2;
}

int main() {
  add(1, 2);

  struct S {};
  // 未找到匹配的函数重载
  // add(S{}, S{});
}