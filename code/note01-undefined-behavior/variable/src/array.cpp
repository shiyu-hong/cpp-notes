#include <iostream>

void process_array() {
  int buffers[3]; // 未初始化数组

  // 危险：操作未初始化的值。
  for (auto i = 0; i < 3; ++i) {
    buffers[i] += 1;
  }

  // 危险：输出随机垃圾值
  // MSVC Debug: 128545369 32760 128545369
  // MSVC Release: 8 1 1
  for (auto i = 0; i < 3; ++i) {
    std::cout << buffers[i] << " ";
  }
}

int main(int argc, char **argv) {
  process_array();

  return 0;
}