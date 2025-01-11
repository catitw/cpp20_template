

template <typename T = int> struct X {};

void test_cpp_standard11() {
  [[maybe_unused]] X<> x1{}; // X<int>, C++11 OK
  [[maybe_unused]] X x2{};   // X<int>, C++11 compile error, C++17 OK
}

// C++17 CTAD only allowed in:
// - global scope
// - function scope
struct Tester {
  // X x1;        // compile error, even in C++17
  X<> x2; // OK
};

int main() { test_cpp_standard11(); }