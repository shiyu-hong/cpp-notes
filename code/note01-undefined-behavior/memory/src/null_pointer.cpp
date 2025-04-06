#include <iostream>

int main(int argc, char **argv) {
  // 空指针。
  int *ptr = nullptr;
  // 危险：将数据写入空指针地址。
  *ptr = 3;
  // 危险：读取空指针内容。
  std::cout << *ptr << std::endl;

  return 0;
}