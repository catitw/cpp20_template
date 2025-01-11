#include "non_template.h"
#include "template_utils.h"

int main() {
  non_template_func();

  // 方式1： 泛型函数定义在头文件中，这种函数具有内部链接
  internal_link_func(12);

  // 方法2： 在头文件中声明模板函数，且在template_impl.cpp中显式实例化
  explicit_func(12);

  // error: undefined reference to `void explicit_func<char const*>(char
  // const*)' explicit_func("12");

  return 0;
}
