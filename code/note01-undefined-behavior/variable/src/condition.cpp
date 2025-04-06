#include <iostream>

void check_condition() {
  bool flag; // 未初始化条件变量。

  // 危险：条件判断可能随机成立。
  // MSVC Debug: Flag is true!
  // MSVC Release: Flag is false!
  if (flag) {
    std::cout << "Flag is true!" << std::endl;
  } else {
    std::cout << "Flag is false!" << std::endl;
  }
}

int main(int argc, char **argv) {
  check_condition();

  return 0;
}