template <typename T, typename T2> struct X {
  void f_T_T2(); // 主模板，声明
};

template <typename T, typename T2> void X<T, T2>::f_T_T2() {} // 类外定义

template <typename T> struct X<void, T> {
  void f_void_T(); // 偏特化，声明
};

template <typename T> void X<void, T>::f_void_T() {} // 类外定义

int main() {
  X<int, int> x;
  x.f_T_T2(); // OK!

  X<void, int> x2;
  x2.f_void_T(); // OK!
}