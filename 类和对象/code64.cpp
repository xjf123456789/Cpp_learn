/*
二进制方式读文件主要利用流对象调用成员函数read

函数原型：istream& read(char *buffer,int len);

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
*/
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // 包含Windows.h头文件以使用system函数
using namespace std;
class Person
{
public:
    char m_Name[64];
    int m_Age;
};
void test01()
{
    ifstream ifs("person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    Person p = {0};
    ifs.read((char *)&p, sizeof(p)); // 读取二进制数据到对象中
    cout << "姓名: " << p.m_Name << endl;
    cout << "年龄: " << p.m_Age << endl;
    ifs.close(); // 关闭文件

}
int main()
{

    // 设置控制台输出中文编码
    SetConsoleOutputCP(CP_UTF8);
    test01();
    system("pause"); // 暂停程序，等待用户输入
    return 0;
}    