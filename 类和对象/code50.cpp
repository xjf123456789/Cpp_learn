#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
/*
静态成员和非静态成员出现同名，处理方式一致
- 访问子类同名成员   直接访问即可
- 访问父类同名成员   需要加作用域
 */
class Base
{
public:
    static void func()
    {
        cout << "Base - static void func()" << endl;
    }
    static void func(int a)
    {
        cout << "Base - static void func(int a)" << endl;
    }
    static int m_A;
};
int Base::m_A = 10;

class Son : public Base
{
public:
    static void func()
    {
        cout << "Son - static void func()" << endl;
    }
    static int m_A;
};
int Son::m_A = 20;
//同名成员属性
void test01()
{
    //通过对象访问
    cout << "通过对象访问" << endl;
    Son s;
    cout <<"Son 下m_A = "<<s.m_A << endl;
    cout <<"Base 下m_A = "<<s.Base::m_A << endl;

    //通过类名访问
    cout << "通过类名访问" << endl;
    cout <<"Son 下m_A = "<<Son::m_A << endl;
    cout <<"Base 下m_A = "<<Son::Base::m_A << endl;
}
//同名成员函数
void test02()
{
    //通过对象访问
    cout << "通过对象访问" << endl;
    Son s;
    s.func();
    s.Base::func();

    //通过类名访问
    cout << "通过类名访问" << endl;
    Son::func();
    Son::Base::func();
    Son::Base::func(100);
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);//解决中文乱码问题
    test01();
    // test02();
    system("pause");
    return 0;

}