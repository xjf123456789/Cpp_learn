#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
/*
**菱形继承问题：**
1.羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
2.草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。
*/
class Animal
{
public:
    int m_Age;
};
//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep:virtual public Animal{};
class Tuo:virtual public Animal{};
class SheepTuo:public Sheep,public Tuo{};
void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 200;

    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);//解决中文乱码问题
    test01();
    system("pause");
    return 0;
    
}
/*
总结：
* 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
* 利用虚继承可以解决菱形继承问题
*/