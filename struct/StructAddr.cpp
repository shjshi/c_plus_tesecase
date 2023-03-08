#include <iostream>
using namespace std;

struct Stu {
    int age;
};

int main() {
    Stu s1;
    cout << &s1 << endl;
    Stu s2 = { };
    cout << &s2 << endl;
    return 0;
}
