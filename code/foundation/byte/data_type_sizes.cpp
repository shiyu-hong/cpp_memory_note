#include <iostream>

int main() {
  // 获取int类型占用的字节数
  size_t int_bytes = sizeof(int);

  // 定义double类型变量并获取其字节数
  double pi = 3.14;
  size_t double_bytes = sizeof pi;

  // 输出两种数据类型的大小
  std::cout << "Size of int: " << int_bytes << std::endl;
  std::cout << "Size of double: " << double_bytes << std::endl;
}