#include "signature.h"
#include <cstddef>

template <typename T> struct X {
  X(T val) : val{val} {}

private:
  T val;
};

// user defined deduction guides
X(int) -> X<std::size_t>;

void test_X() {
  X x1{1}; // deducte to X<std::size_t>
  print_typename(x1);

  X x2{1l}; // X<long>
  print_typename(x2);
}

// ----------------------------------------------------------------------------

template <typename Ty, std::size_t size> struct Array {
  Ty arr[size];
};

template <typename T, typename... RestArgs>
Array(T, RestArgs...) -> Array<T, sizeof...(RestArgs) + 1>;

void test_Array() {
  [[maybe_unused]] Array arr{1, 2};
  ;
}

int main() {
  test_X();
  test_Array();
}