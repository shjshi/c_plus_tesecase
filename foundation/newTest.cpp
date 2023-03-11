#include <iostream>
#include<thread>

using namespace std;

/**
C++中 new 一个对象的时候加括号和不加括号的区别

对于有构造函数的类，不论有没有括号，都用构造函数进行初始化

如果没有构造函数
不加括号的new只分配内存空间，不进行内存的初始化
而加了括号的new会在分配内存的同时初始化为0。

int* p = new int;//p指向的int值是不确定的；
int* q = new int();//q指向的int值为0。
 */
int main() {
    int *p = new int;//p指向的int值是不确定的；
    cout << p << endl;
    cout << *p << endl;
    int *q = new int();//q指向的int值为0。
    cout << q << endl;
    cout << *q << endl;
    return 0;
}