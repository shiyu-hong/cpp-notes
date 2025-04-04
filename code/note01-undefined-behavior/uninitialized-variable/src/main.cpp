#include <iostream>

class Point {
public:
  void print() { std::cout << "(" << x_ << ", " << y_ << ")" << std::endl; }

private:
  int x_; // 未在构造函数中初始化
  int y_; // 未在构造函数中初始化
};

void unsafe_calculation();

void process_array();

void log_point();

void dangerous_pointer_operation();

int main(int argc, char **argv) {
  dangerous_pointer_operation();
  return 0;
}

void unsafe_calculation() {
  int a; // 危险：未初始化局部变量
  int b = 10;
  int result = a + b; // 未定义行为（未初始化的变量 a 可能包含垃圾值）

  std::cout << result << std::endl; // 输出随机垃圾值
}

void process_array() {
  int buffer[3]; // 危险：未初始化数组

  for (auto i = 0; i < 3; ++i) {
    buffer[i] += 1; // 未定义行为（操作未初始化的值）
  }

  for (auto i = 0; i < 3; ++i) {
    std::cout << buffer[i] << " "; // 输出随机垃圾值
  }
}

void log_point() {
  Point point;   // 危险：未显示初始化成员
  point.print(); // 输出随机垃圾值
}

void dangerous_pointer_operation() {
  int *ptr; // 危险：未初始化指针
  *ptr = 3; // 未定义行为（可能覆盖随机内存，触发段错误）
}