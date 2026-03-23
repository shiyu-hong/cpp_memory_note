#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 演示常量左值引用可延长临时对象生命周期
 *
 * @note 临时对象存活至引用作用域结束
 */
void test_const_lvalue_reference() {
  const auto& ref = std::string("temp"); // 临时对象绑定到常量引用
  std::cout << "const ref: " << ref << '\n';
  // ref销毁时，临时对象一并销毁
}

/**
 * @brief 演示临时对象不能绑定到非常量左值引用
 *
 * @note 编译错误：右值无法绑定到非常量左值引用
 */
void test_nonconst_lvalue_reference() {
  auto& ref = std::string("error"); // 编译错误
}

/**
 * @brief 演示右值引用绑定临时对象及移动语义
 *
 * @note 右值引用可修改临时对象，支持移动操作
 */
void test_rvalue_reference() {
  auto&& rref = std::string("Hello,"); // 临时对象绑定到右值引用
  rref += "World!";                    // 可修改临时对象

  std::vector<std::string> vec;
  vec.push_back(std::move(rref)); // 移动语义：资源转移，避免拷贝

  std::cout << "rref (moved): " << rref << '\n'; // 移动后rref为空
  std::cout << "vec[0]: " << vec[0] << '\n';     // 打印：Hello,World!
}

/**
 * @brief 错误示例：返回局部临时对象的引用
 *
 * @return 悬空引用（函数结束后对象已销毁）
 * @warning 禁止返回局部对象的引用
 */
const std::string& broken_heart() {
  return std::string("error"); // 危险：临时对象在函数结束时销毁
}

/**
 * @brief 演示悬空引用的未定义行为
 *
 * @warning 函数返回的临时对象无法通过引用延长生命周期
 */
void test_lifetime_rule() {
  const auto& leaked = broken_heart();                     // leaked指向已销毁的内存
  std::cout << "broken heart: " << broken_heart() << '\n'; // 未定义行为：导致程序崩溃
}

int main() {
  test_const_lvalue_reference();    // 常量左值引用 - 生命周期延长
  test_nonconst_lvalue_reference(); // 非常量左值引用 - 编译错误
  test_rvalue_reference();          // 右值引用 - 移动语义
  test_lifetime_rule();             // 悬空引用 - 程序运行时崩溃
}