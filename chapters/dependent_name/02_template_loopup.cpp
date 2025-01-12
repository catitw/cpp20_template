// 模板定义中不是当前实例化的成员的待决名同样不被认为是模板名，
// 除非使用消歧义关键词 template，或它已被设立为模板名

template <typename T> struct S {
  template <typename U> void foo() {}
};

template <typename T> void bar() {
  S<T> s;
  // s.foo<T>();          // 错误：< 被解析为小于运算符
  // note: 可能存在struct S的特化，在这个特化中，foo函数不存在等类似情形
  s.template foo<T>(); // OK
}

int main() {
  bar<int>();
  ;
}