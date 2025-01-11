#include "header.h"

void test_case1() {
  [[maybe_unused]] Case1<int> c{}; // class template substitute ok
  //   c.foo(); // link error (note: member function not instanted)
}

void test_case2() {
    Case2<int> c{};
    c.foo();
}

int main() {
  test_case1();
  test_case2();

  return 0;
}