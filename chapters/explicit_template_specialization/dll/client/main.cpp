#include "header.h"
#include <string>

using namespace std::string_literals;

int main() {
  f(1);
  f("abc"s);
  // link error(未显式实例化)
  // f(2.0);

  X<int>{}.f();
  X<std::string>{}.f();
  // link error(未显式实例化)
  // X<double>{}.f();
}