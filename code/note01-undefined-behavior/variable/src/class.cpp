#include <iostream>

class Point {
public:
  void print() { std::cout << "(" << x_ << ", " << y_ << ")" << std::endl; }

private:
  int x_; // 未在构造函数中初始化
  int y_; // 未在构造函数中初始化
};

void log_point() {
  Point point;   // 未显示初始化成员
  point.print(); // 输出随机垃圾值
}

int main(int argc, char **argv) {
  log_point();

  return 0;
}