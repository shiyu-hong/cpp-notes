#include <iostream>

void check_condition() {
  bool flag;  // 未初始化条件变量
  if (flag) { // 未定义行为（条件判断可能随机成立）
    std::cout << "Flag is true!" << std::endl;
  } else {
    std::cout << "Flag is false!" << std::endl;
  }
}

int main(int argc, char **argv) {
  check_condition();
  
  return 0;
}