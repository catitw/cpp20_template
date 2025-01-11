#pragma once

#include <iostream>

template <typename T> void internal_link_func(T t) {
  std::cout << "internal_link_func: " << t << '\n';
}

template <typename T> void f(T);

// [阻止隐式实例化](https://stackoverflow.com/questions/8130602/using-extern-template-c11-to-avoid-instantiation)
//
// 由于放在头文件中，所有翻译单元都会阻止实例化，
// 但是我们在 `impl.cpp` 明确的显示实例化了它，
// 因此只有一个翻译单元定义了这个符号
extern template void f<int>(int);
