#include "non_template.h"
#include "template_utils.h"
#include <iostream>

void non_template_func() {
  std::cout << "non_template_func, calling internal_link_func:" << '\n';
  internal_link_func(12);
  std::cout << "non_template_func, calling internal_link_func end" << '\n';
}
