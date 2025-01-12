#include <cstdio>
#include <type_traits>

// 要求传入的对象需要支持`+`, 需要有别名 type ，成员 value、f
template <typename T,
          typename SFINAE = std::void_t<
              // T{} + T{} 的方式要求 T 支持`operator +`,
              // 同时还要有默认构造函数,
              decltype(std::declval<T>() + std::declval<T>()), typename T::type,
              decltype(&T::value), decltype(&T::f)>>
auto add(const T &t1, const T &t2) {
  std::puts("SFINAE + | typename T::type | T::value");
  return t1 + t2;
}

struct Test {
  int operator+(const Test &t) const { return this->value + t.value; }
  void f() const {}
  using type = void;
  int value;
};

int main() {
  Test t{1}, t2{2};
  add(t, t2);

  // 未找到匹配的重载函数
  // add(1, 2);
}