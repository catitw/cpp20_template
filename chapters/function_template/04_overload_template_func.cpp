
#include <iostream>
template <typename T> void test(T) { std::cout << "template func" << '\n'; }

void test(int) { std::cout << "int" << '\n'; }

int main() {
  test(1);

  test("1");
  test(1.2);
}
