#include <iostream>

int main() {
  // 定义布尔变量 flag，初始值设为 false
  bool flag{false};

  // 使用 sizeof 获取 flag 的内存大小，并输出结果
  std::cout << "Size of boolean variable: " << sizeof(flag) << " byte.\n";
}
