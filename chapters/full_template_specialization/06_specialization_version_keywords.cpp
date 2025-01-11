/**
 * 函数模板和变量模板的显式特化是否为 inline/constexpr/constinit/consteval，
 * 只与显式特化自身有关，主模板的声明是否带有对应说明符对它没有影响。
 * 模板声明中出现的属性在它的显式特化中也没有效果。
 **/

template <typename T> int f(T) { return 6; }

// OK，f<int> 是以 constexpr 修饰的
template <> constexpr int f<int>(const int) { return 6; }

// 这里声明的 constexpr 修饰函数模板是无效的
template <class T> constexpr T g(T) { return 6; }

// OK，g<int> 不是以 constexpr 修饰的
template <> int g<int>(int) { return 6; }

int main() {
  // OK，f<int> 是以 constexpr 修饰的，可以编译期求值
  [[maybe_unused]] constexpr auto n = f<int>(0);

  // Error! f<double> 不可编译期求值
  // constexpr auto n2 = f<double>(0);

  // Error! 函数模板 g<int> 不可编译期求值
  // constexpr auto n3 = g<int>(0);

  // OK! 函数模板 g<double> 可编译期求值
  [[maybe_unused]] constexpr auto n4 = g<double>(0);
}
