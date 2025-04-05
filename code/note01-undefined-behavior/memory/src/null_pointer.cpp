#include <iostream>

int main(int argc, char **argv) {
  int *ptr = nullptr; // 显示初始化为空指针

  // 未定义行为：解引用空指针
  *ptr = 3;                       // 危险：将数据写入空指针地址
  std::cout << *ptr << std::endl; // 危险：读取空指针内容

  return 0;
}