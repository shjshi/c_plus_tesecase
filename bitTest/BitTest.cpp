#include <iostream>
#include<thread>

using namespace std;

int main1() {
    uint8_t data[2];
    uint16_t version;
    data[0] = 0x01;
//    printf("%04x \n",data[0]); //输出 0100
    version = data[0] << 8;
    data[1] = data[0] << 8;
    printf("%04x \n",data[0]); //输出 0100
    printf("%04x \n",data[1]); //输出 0000
    printf("%04x \n",version); //输出 0100
    return 0;
}

int main() {
    uint8_t c = 65;
    cout<<c<<endl;
    int b = c<<8; // <<8 = 65 x 2^8
    cout<<b<<endl;
    return 0;
}
