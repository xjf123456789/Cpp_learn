#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
/*
> 总结： 多继承中如果父类中出现了同名情况，子类使用时候要加作用域
*/

//多继承语法：class 子类：继承方式 父类1 ，继承方式 父类2
class Base1
{
public:
    Base1()
    {
        m_A = 100;
    }
public:
    int m_A;
};
class Base2
{
public:
    Base2()
    {
        m_A = 200;//开始是m_B不会出现问题，但是改为m_A就会出现问题
    }
public:
    int m_A;
};
//语法：class 子类：继承方式 父类1 ，继承方式 父类2 
class Son :public Base1, public Base2
{
public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }

public:
    int m_C;
    int m_D;
};
//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test01()
{
    Son s;
    cout << "sizeof(Son) = " << sizeof(s) << endl;
    cout << "s.Base1::m_A = " << s.Base1::m_A << endl;
    cout << "s.Base2::m_A = " << s.Base2::m_A << endl;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);//解决中文乱码问题
    test01();
    system("pause");
    return 0;
}