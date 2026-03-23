#include <iostream>
#include <string>
#include <type_traits>

/**
 * @brief 检查类型是否为对象类型并打印结果
 *
 * @tparam T 待检测的类型
 * @param type_name 类型名称
 */
template <typename T>
void print_is_object_type(const std::string& type_name) {
  constexpr bool is_object{std::is_object_v<T>};

  std::cout << std::boolalpha;
  std::cout << "Type '" << type_name << "' is an object type: " << is_object << '\n';
}

int main() {
  // 测试算术类型
  print_is_object_type<int>("int");
  // 测试指针类型
  print_is_object_type<int*>("int*");
  // 测试引用类型
  print_is_object_type<int&>("int&");
  // 测试函数类型
  print_is_object_type<decltype(main)>("decltype(main)");
}

int a;