
#include <iostream>
#include <cstdint>

using namespace std;

/**
 * 用数组，取出指针各个字节中的数据
 * @return
 */
int main() {

    // 定义一个指针
    char *str = "hello";
    cout<<(str+1)<<endl;// ello，也就是说+1就是从第二个字符开始到\0
    cout<<sizeof("hello")<<endl;
    for (int i = 0; i < sizeof("hello"); ++i) {

        // 用数组取出每个字节的值
        cout<<str[i]<<",";
    }
    return 0;
}