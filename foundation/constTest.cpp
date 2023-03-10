#include <iostream>
#include<thread>

using namespace std;
/**
 * const 不同位置 是什么意思？
 * @return
 */
int main() {
    const char *a = "abc";
    char * const b = "b";
    const char * const c = "c";

    cout<<a<<endl;// abc           字符串
    cout<<&a<<endl;// 0xe577dffbd8 地址
    cout<<*a<<endl;// a            第一个字符

//    a = "xxx"; √
//    *a = 'a'; ×
//    b = "xxx"; ×
//    *b = 'b'; √
//    c = "xxx"; ×
//    *c = 'c'; ×
    return 0;
}