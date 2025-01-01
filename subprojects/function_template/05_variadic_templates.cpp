

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <type_traits>
void helper_f1(const char *, int) { std::cout << "f1" << '\n'; }
void helper_f1(const char **, int *) { std::cout << "&f1" << '\n'; }

// Args: 类型形参包，可接受0或多个类型
// args: 函数形参包，存储实参
// args... : 展开实参
template <typename... Args> void f1(Args... args) {
  helper_f1(args...);  // print "f1"
  helper_f1(&args...); // print "&f1"
}

void test_f1() {
  f1("abc", 1);

  // error: no matching function for call to ‘helper_f1(const char*&, int&,
  // int&)’
  // f1("abc", 1, 2);
}

// `...`之前的`const Args&`称之为模式，每一次替换都遵循模式
template <typename... Args> void print(const Args &...args) {

  // 此处的模式为 `(std::cout << args << ' ', 0)`
  int _[]{(std::cout << args << ' ', 0)...};
  std::cout << '\n';

  // 相当于:
  // int _[] {
  //   (std::cout << arg0 << ' ', 0), // 0为括号内的逗号表达式的结果
  //   (std::cout << arg1 << ' ', 0),
  //   (std::cout << arg2 << ' ', 0),
  // };
}

void test_print() {
  // print "abc 1 1.2"
  print("abc", 1, 1.2);
}

template <typename T, std::size_t N, typename... Args>
void f3(const T (&array)[N],
        Args... index) { // array是对内建数组类型的变量的引用
  // 此处的模式为 `array[index]
  print(array[index]...);
}

void test_f3() {
  int array[]{1, 2, 3};
  f3(array, 0, 2); // T=int, N=3

  {
    // int *p = static_cast<int *>(malloc(sizeof(int) * 4));
    // p[0] = 3;

    // // error: no matching function for call to ‘f3(int*&, int)’
    // f3(p, 0);
  }
}

template <typename... Args, typename R = std::common_type_t<Args...>>
R sum_v1(const Args &...args) {

  R arr[]{static_cast<R>(args)...};
  R s{};

  for (std::size_t i = 0; i < sizeof...(args); ++i) {
    s += arr[i];
  }

  return s;
}

template <typename... Args, typename R = std::common_type_t<Args...>>
R sum_v2(const Args &...args) {
  R _[]{static_cast<R>(args)...};
  return std::accumulate(std::begin(_), std::end(_), R{}); // `R{}` 为初始值
}

void test_sum() {
  std::cout << sum_v1(1, 1, 1.1) << '\n';
  std::cout << sum_v2(1, 1, 1.1) << '\n';
}

int main() {
  test_f1();

  test_print();

  test_f3();

  test_sum();
}
