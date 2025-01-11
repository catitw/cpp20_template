#pragma once

#include <format>
#include <iostream>

#define PRINT_FUNC_SIGNATURE()                                                 \
  {                                                                            \
    std::cout << std::format("{}\n", __PRETTY_FUNCTION__);                     \
  }
