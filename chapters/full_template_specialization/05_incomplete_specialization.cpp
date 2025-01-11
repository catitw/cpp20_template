template <class T> class X;

template <> // 特化（声明，不定义）
class X<int>;

X<int> *p; // OK：指向不完整类型的指针
// X<int> x;        // 错误：不完整类型的对象

int main() {}