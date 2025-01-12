#include <iostream>

// 定义一个concept(即谓词)
template <typename T>
concept Addable = requires(T a) { a + a; };

template <Addable T> // 应用concept
auto add(const T &t1, const T &t2) {
  return t1 + t2;
}

int main() {
  std::cout << ::add(1, 2) << '\n';

  struct X {};
  // compile note: the required expression ‘(a + a)’ is invalid
  // and error: no matching function for call to ‘add(main()::X, main()::X)’
  // std::cout << ::add(X{}, X{}) << '\n';

  // concept可以在编译期求值
  constexpr bool v = Addable<int>;
  std::cout << std::boolalpha << v << '\n';
}