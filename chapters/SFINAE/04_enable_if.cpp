#include <iostream>
#include <type_traits>

// 要求 T 为 int 类型
template <typename T,
          typename SFINAE = std::enable_if_t<std::is_same_v<T, int>>>
void f(T) {
  std::cout << "void f(T)" << '\n';
}

int main() {
  f(1);

  // 代换失败，错误为无法找到对应的重载
  // f(1.2);
}