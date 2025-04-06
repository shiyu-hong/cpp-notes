#include <iostream>

class Point {
public:
  void print() { std::cout << "(" << x_ << ", " << y_ << ")" << std::endl; }

private:
  int x_; // 未在构造函数中初始化。
  int y_; // 未在构造函数中初始化。
};

void log_point() {
  Point point; // 未显示初始化成员。

  // 危险：输出随机垃圾值。
  // MSVC Debug: (-1289063848, 32759)
  // MSVC Release: (0, 0)
  point.print();
}

int main(int argc, char **argv) {
  log_point();

  return 0;
}