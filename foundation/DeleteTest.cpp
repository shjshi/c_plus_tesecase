//
// Created by shj on 2023/3/8.
//
#include <iostream>

using namespace std;

class Dog {
public:
    string name = "jess";

    ~Dog() {
        cout << name << "���ͷ�" << endl;
    }
};
/**
delete�ؼ���

ʹ�÷���
delete obj;
delete(obj);

c++���кܶ�ط����ȿ��������ţ��ֿ���û�����ţ���֪����û������
Ŀǰ������û������ģ�����д������֪��������Բ鿴���ٷ��Ķ���
 */
int main() {
    // ����new�ؼ��ִ������󣬳���������Զ���������������������Դ���ͷ�
    Dog dog;
    cout << "����һֻС�� " << dog.name << endl;
    dog.name = "shj";
    cout << "�޸����ֽ� " << dog.name << endl;

    // ��new�ؼ��ִ����Ķ��󣬱������delete���������������Żᱻ��������Դ�Żᱻ�ͷ�
    // ���������delete�������ͻᵼ���ڴ�й¶
    Dog *dog1 = new Dog;
    cout << "�ִ���һֻС�� " << dog1->name << endl;

    // delete������ʹ�÷���
//    delete dog1;
    delete (dog1);

    return 0;
}