//
// Created by wisky on 2023/3/10.
//
// x表示以小写的十六进制数输出；4表示输百出的十六进制数的宽度是4个字符；0表示输出的十六进制数中，不足4个字符的部分，用“0”来补度充，以达到4个字符的宽度。操作方法如下：

#include <iostream>
#include<thread>

using namespace std;

int main() {
    int a = 2;
    printf("a=%x\n",a); // a=2        %x：用16进制输出
    printf("a=%0x\n",a); //a=   2     4:宽度是4个字符
    printf("a=%4x\n",a); //a=   2     4:宽度是4个字符
    printf("a=%04x\n",a); //a=0002    0:不足4个字符的部分，用“0”来补度充

    uint8_t data[2];
    data[0] = 0x01;
    data[1] = data[0] << 8;
    printf("%04x \n",data[0]); //输出 0001
    printf("%04x \n",data[1]); //输出 0000

    uint8_t data2[2];
    data2[0] = 10;
    data2[1] = data2[0] << 8;
    printf("%04x \n",data2[0]); //输出 000a
    printf("%04x \n",data2[1]); //输出 0000
    return 0;
}