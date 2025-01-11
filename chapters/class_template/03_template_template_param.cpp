#include "signature.h"
#include <cstddef>

template <typename T, std::size_t N> struct Array {
  T arr[N];
};

// T 是一个 `template template param`, 是一个整体
// 在这个示例中，T是既可以接收两个泛型(一个模板形参和一个非类型模板形参)的泛型
template <typename T, std::size_t N = 10,
          template <typename, std::size_t> typename C = Array // newline
          >
struct Container {
  C<T, N> container;
};

int main() {
  Container<int> c1;
  print_typename(c1);

  Container<int, 100> c2;
  print_typename(c2);
}