#include <cstddef>
#include <type_traits>

template <typename Ty, std::size_t size> //
struct array {
  Ty arr[size];
};

// 推导指引
template <class FType, class... Rest>
array(FType, Rest...)
    -> array<std::enable_if_t<(std::is_same_v<FType, Rest> && ...), FType>,
             sizeof...(Rest) + 1>;

int main() {
  [[maybe_unused]] ::array arr1{1, 2, 2};

  // SFINAE 失败
  // ::array arr2{1, 2.2, 2};
}
