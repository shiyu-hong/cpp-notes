#include <iostream>

int main(int argc, char **argv) {
  int *ptr; // 未初始化指针
  *ptr = 3; // 未定义行为（可能覆盖随机内存，触发段错误）

  return 0;
}