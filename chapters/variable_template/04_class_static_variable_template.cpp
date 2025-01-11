#include <iostream>
struct Note {
  static int a;            // declaration
  static const int b = 20; // declaration, special case, see follwing comment

  static inline int c = 20;    // definition
  static constexpr int d = 20; // definition(C++17 rule: `constexpr static`
                               // implicite `inline` keyword)
};

// read always ok, but operation like (written, its address is taken, or a
// reference is bound to it) will be undefined behaviour before we define this
// variable.
int Note::a = 20; // definition

// if we don't have this line `const int Note::b;`,
// then expression `Note::b` ok,
// but expression `&Note::b` has undefined behaviour:
//
// - One and only one definition of every non-inline function or variable that
// is odr-used (see below) is required to appear in the entire program. The
// compiler is not required to diagnose this violation, but the behavior of the
// program that violates it is undefined.
//
// - how to specify a variable is odr-used:
// An object is odr-used if its value is read (**unless it is a compile time
// constant**) or written, its address is taken, or a reference is bound to it,
//
// so, in summay:
// if a variable is odr-used, then the **one and only one definition** is
// required to appear in the entire program.
// and the expression `&Note::b` is the so-called `odr-used`, so the definition
// is required, but we not provide it, and undefined behaviour.
// but, the expression `Note::b` **is not `odr-used`**, and we not required to
// provide it, and ok.

// > summary: if a variable is `odr-used`, then ODR is required to meet, we need
//   to provide the defition.
//
// > [Definitions and ODR (One Definition Rule)]
//   (https://en.cppreference.com/w/cpp/language/definition)
const int Note::b;

// -----------------------------------------------------------------------------

struct limits {
  template <typename T> static const T min; // declartion, see previous examples

  template <typename T> static inline const T mid{}; // definition
  template <typename T> static constexpr T max{};    // definition
};

template <typename T> const T limits::min{};

int main() {
  std::cout << ::limits::min<int> << '\n';
  std::cout << ::limits::mid<int> << '\n';
  std::cout << ::limits::max<int> << '\n';
}