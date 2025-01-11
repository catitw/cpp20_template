#include <ios>
#include <iostream>
#include <type_traits>

// -----------------------------     case1     ---------------------------------
template <typename T> // primary template
struct is_void {
  // note: static variable member belong to class, not class template
  static constexpr bool value = false;
};

template <> // explicit specialization for T=void
struct is_void<void> {
  static constexpr bool value = true;
};

template <typename T> constexpr bool is_void_v{::is_void<T>::value};

void test_case1() {
  std::cout << std::boolalpha << ::is_void<int>::value << '\n';  // false
  std::cout << std::boolalpha << ::is_void<void>::value << '\n'; // true

  std::cout << std::boolalpha << ::is_void_v<int> << '\n';  // false
  std::cout << std::boolalpha << ::is_void_v<void> << '\n'; // true

  std::cout << '\n';

  // in STL way:
  std::cout << std::boolalpha << std::is_void<int>::value << '\n';
  std::cout << std::boolalpha << std::is_void<void>::value << '\n';

  std::cout << std::boolalpha << std::is_void_v<int> << '\n';
  std::cout << std::boolalpha << std::is_void_v<void> << '\n';
}

// -----------------------------     case2     ---------------------------------

template <typename T> struct X {
  void f() const { std::cout << "X<T>::f()" << '\n'; }
};

template <> struct X<std::string> {
  void f() const { std::cout << "X<std::string>::f()" << '\n'; }

  int n = 1;
};

void test_case2() {
  X<int>{}.f();    // X<T>::f()
  X<double>{}.f(); // X<T>::f()

  // error: No member named 'n' in 'X<int>'
  // std::cout << X<int>{}.n << '\n';

  auto xs = X<std::string>{};
  xs.f(); // X<std::string>::f()
  std::cout << xs.n << '\n';
}

int main() {
  std::cout << "case1:";
  test_case1();

  std::cout << "\ncase2:\n";
  test_case2();
}