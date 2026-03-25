#include <iostream>

int main() {
  // 使用 sizeof 运算符获取 int 类型占用的字节数
  size_t int_bytes{sizeof(int)};

  // 定义浮点变量 flag，初始值设为 3.14
  double pi{3.14};
  // 获取 pi 变量占用的字节数，sizeof 作用于变量时括号可省略
  size_t double_bytes{sizeof pi};

  // 依次输出 int 和 double 类型占用的字节数
  std::cout << "Size of int: " << int_bytes << '\n';
  std::cout << "Size of double: " << double_bytes << '\n';
}
