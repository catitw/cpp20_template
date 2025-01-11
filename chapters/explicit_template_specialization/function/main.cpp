#include "header.h"
#include "utils.h"

int main() {
    // 方式1： 泛型函数定义在头文件中，这种函数具有内部链接
  internal_link_func(12);

  // 方法2： 在头文件中声明模板函数，且在impl.cpp中显式实例化
  f(1); // OK

  util_func();

  // compile error: undefined reference to `void f<char>(char)'
  // f('a');
}