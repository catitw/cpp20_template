
template <typename T> struct Note {

  // NOTE: for this case, not member function template,
  // just plain function when class template substitute
  void foo(T t) {}
};

struct C {

  // member function template
  template <typename T> void foo(T t) {}
};

int main() {
  C c{};

  c.foo(1);
  c.foo("text");
}