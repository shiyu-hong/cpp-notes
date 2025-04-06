#include <iostream>

int main(int argc, char **argv) {
  int x;        // 未初始化局部变量。
  int y{10};    // 初始化局部变量。
  int z{x + y}; // 危险：变量 x 未初始化，可能包含随机垃圾值。

  // 危险：输出随机垃圾值。
  // MSVC Debug: -840574134
  // MSVC Release: 10
  std::cout << z << std::endl;

  return 0;
}