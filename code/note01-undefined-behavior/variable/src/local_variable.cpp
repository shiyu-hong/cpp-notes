#include <iostream>

int main(int argc, char **argv) {
  int x;        // 未初始化局部变量
  int y{10};    //
  int z{x + y}; // 未定义行为（变量 x 未初始化，可能包含随机垃圾值）

  std::cout << z << std::endl; // 输出随机垃圾值

  return 0;
}