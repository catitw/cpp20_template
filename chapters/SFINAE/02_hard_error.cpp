template <typename A> //
struct MyClass {
  using type = typename A::type;
};

template <typename T> void foo(double) {}

// -----------------------------     case1     ---------------------------------
// 如果对代换后的类型/表达式的求值导致副作用，例如实例化某模板特化、生成某隐式定义的成员函数等，
// 那么这些副作用中的错误都被当做硬错误。
//
// 这个版本会导致出现硬错误，而非代换错误.
//
// template <class T,
//           class V = typename MyClass<T>::type> // hard error if B has no
//                                                // member `type`
// void foo(int) {}

// -----------------------------     case2     ---------------------------------

template <class T,
          class U = typename T::type,          // SFINAE failure if T has
                                               // no member `type`，stop
          class V = typename MyClass<T>::type> // hard error if B has no
                                               // member `type`
void foo(int) {}

int main() {
  foo<void>(1);
  ;
}
