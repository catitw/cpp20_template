#include "header.h"
#include "utils.h"

int main() {
  InlineClass<int> inlineC{};
  inlineC.f();

  ExternFuncClass<int> externC{};
  externC.f();

  // compile error: undefined reference to `ExternFuncClass<double>::f()'
  // ExternFuncClass<double>{}.f();

  util_func();
}