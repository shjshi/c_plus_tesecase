//
// Created by shj on 2023/3/8.
//
#include <iostream>

using namespace std;

class Dog {
public:
    string name = "jess";

    ~Dog() {
        cout << name << "被释放" << endl;
    }
};

int main() {
    // 不用new关键字创建对象，程序结束后，自动调用析构函数，进行资源的释放
    Dog dog;
    cout << "创建一只小狗 " << dog.name << endl;
    dog.name = "shj";
    cout << "修改名字叫 " << dog.name << endl;

    // 用new关键字创建的对象，必须调用delete函数，析构函数才会被触发，资源才会被释放
    // 如果不调用delete函数，就会导致内存泄露
    Dog *dog1 = new Dog;
    cout << "又创建一只小狗 " << dog1->name << endl;

    // delete的两种使用方法
//    delete dog1;
    delete (dog1);

    return 0;
}