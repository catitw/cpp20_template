#include "signature.h"
#include <cxxabi.h>

#ifdef _MSC_VER
std::string demangle(const char *name) {
  return name;
}
#else
std::string demangle(const char *name) {
  int status = 0;
  char *demangled = abi::__cxa_demangle(name, nullptr, nullptr, &status);
  if (status == 0) {
    std::string result(demangled);
    free(demangled);
    return result;
  } else {
    return name;
  }
}
#endif