#pragma once

template <typename T> struct Case1 {
  void foo();
};

template <typename T> struct Case2 {
  void foo();
};

// next line not necessary
extern template void Case2<int>::foo();
