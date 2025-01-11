template <typename T> // 主模板
void f(const T &) {}

void f2() {
  f(1); // implicit specialize f<int>, f<int> will be defined.
}

// what is specialization:
//
// tempate<>    // specialization(declaration, not definition)
// void f<int>(const int &);

// error: Explicit specialization of 'f<int>' after instantiaztion
//
// template <>
// void f<int>(const int &) {}

int main() {}