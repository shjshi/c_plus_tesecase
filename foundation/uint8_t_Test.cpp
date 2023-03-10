/*
 *
一、在C语言中有6种基本数据类型：short、int、long、float、double、char
1、数值类型
    1）整型：short、int、long
    2）浮点型：float、double
2、字符类型：char

二、typedef回顾
typedef 用来定义 关键字 或 标识符 的 别名
 例如：
  typedef double wages;
  typedef wages salary;

三、uint8_t\uint_16_t\uint32_t\uint64_t
1、这些类型的来源：
 这些数据类型中都带有_t, _t 表示这些数据类型是通过typedef定义的，而不是新的数据类型。也就是说，它们其实是我们已知的类型的 别名。

2、使用这些类型的原因：
    方便代码的维护。
    比如，在C中没有bool型，于是在一个软件中，一个程序员使用int，一个程序员使用short，会比较混乱。最好用一个typedef来定义一个统一的bool：
    typedef char bool;
    在涉及到跨平台时，不同的平台会有不同的字长，所以利用 预编译 和 typedef 可以方便的维护代码。

3、这些类型的定义：
在C99标准中定义了这些数据类型，具体定义在：/usr/include/stdint.h

4、格式化输出
 uint16_t %hu
 uint32_t %u
 uint64_t %llu

5 、uint8_t类型的输出：
注意uint8_t的定义为
typedef unsigned char uint8_t;

uint8_t实际上是一个char，所以输出uint8_t类型的变量实际上输出其对应的字符，而不是数值。
 例：
uint8_t num = 67;
cout << num << endl;
输出结果：C
 */

#include <iostream>

using namespace std;

int main() {
    uint8_t num = 67;
    cout << num << endl; // C
    return 0;
}