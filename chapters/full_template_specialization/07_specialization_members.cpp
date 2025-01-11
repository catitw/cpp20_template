template <typename T> struct A {
  // 成员类
  struct B {};

  // 成员类模板
  template <class U> struct C {};
};

// -----------------------------     case1     ---------------------------------

template <> struct A<void> {
  // 类内声明
  void f();
};

// 类外定义
void A<void>::f() {
  // todo
}

// -----------------------------     case2     ---------------------------------
// 特化成员类
// 特化 A<char> 的情况下 B 类的定义

template <> struct A<char>::B { // 特化 A<char>::B
  void f();                     // 类内声明
};

void A<char>::B::f() { // 类外定义
}

// -----------------------------     case3     ---------------------------------
// 特化成员类模板
// 特化 A<int> 情况下模板类 C 的定义

template <>        // newline
template <class U> // newline
struct A<int>::C {
  void f(); // 类内声明
};

// template<> 会用于定义被特化为类模板的显式特化的成员类模板的成员
template <>              // newline
template <class U>       // newline
void A<int>::C<U>::f() { // 类外定义
}

// -----------------------------     case4     ---------------------------------
// 特化类的成员函数模板

struct X {
  template <typename T> void f(T) {}
};

template <> // 类外特化
void X::f<double>(double) {}

// -----------------------------     case5     ---------------------------------
// 特化类模板的成员函数模板

template <typename T> struct Y {
  template <typename T2> void f(T2) {}
};

template <>
template <>
void Y<void>::f<double>(double) { // 类外特化，对于 X<void>::f<double> 的情况
}

int main() {}