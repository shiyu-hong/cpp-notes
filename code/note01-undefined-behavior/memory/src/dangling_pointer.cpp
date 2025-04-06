#include <iostream>

// （1）释放指针后未将其置空会形成野指针。
void foo1() {
  // 动态分配内存。
  int *ptr = new int(10);
  // 内存释放后，指针 ptr 仍保留原内存地址，成为野指针。
  delete ptr;
  // 危险：访问野指针指向的内存可能引发段错误，导致程序异常终止。
  *ptr = 3;
  // 危险：访问无效内存区域可能导致读取到垃圾值或引发段错误。
  std::cout << *ptr;
}

// （2）函数返回局部变量的内存地址会导致未定义行为。
int *create_dangling_pointer() {
  // 局部变量在栈上分配。
  int x{5};
  // 危险：函数返回后，其栈帧中的局部变量会被自动销毁，
  // 此时返回的指针将指向无效的栈内存，访问该指针会导致未定义行为。
  return &x;
}

void foo2() {
  int *ptr = create_dangling_pointer();
  // 危险：访问已释放的栈内存可能导致读取到垃圾值或引发段错误。
  std::cout << *ptr;
}

// （3）多个指针指向同一内存。
void foo3() {
  // 动态分配内存。
  int *p1 = new int(3);
  // p1 和 p2 指向同一块内存。
  int *p2 = p1;
  // 内存释放后，指针 p1 和 p2 仍保留原内存地址，成为野指针。
  delete p1;
  // 危险：访问野指针指向的内存可能引发段错误，导致程序异常终止。
  *p2 = 3;
}

// （4）数组越界访问。
void foo4() {
  int arr[3]{1, 2, 3};
  int *ptr = &arr[0];
  // 危险：指针越界访问可能指向未分配的未知内存区域，导致未定义行为或内存访问冲突。
  ptr += 5;
  // 危险：访问野指针指向的内存可能引发段错误，导致程序异常终止。
  *ptr = 4;
}

// （5）对象成员指针失效。
struct Foo {
public:
  int *data;

public:
  Foo() { data = new int(3); }

  ~Foo() { delete data; }
};

void foo5() {
  Foo foo;
  // 复制指向数据的指针。
  int *ptr = foo.data;
  // 显示释放内存后未置空指针（或在对象析构后未处理成员指针），导致产生野指针。
  delete foo.data;
  // 危险：访问野指针指向的内存可能引发段错误，导致程序异常终止。
  *ptr = 1;
}

int main(int argc, char **argv) {
  foo5();
  return 0;
}