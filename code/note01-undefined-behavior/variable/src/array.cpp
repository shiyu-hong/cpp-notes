#include <iostream>

void process_array() {
  int buffers[3];    // 未初始化数组

  for (auto i = 0; i < 3; ++i) {
    buffers[i] += 1; // 未定义行为（操作未初始化的值）
  }

  for (auto i = 0; i < 3; ++i) {
    std::cout << buffers[i] << " "; // 输出随机垃圾值
  }
}

int main(int argc, char **argv) {
  process_array();

  return 0;
}