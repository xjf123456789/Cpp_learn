/*
当类模板碰到继承时，需要注意一下几点：
* 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
* 如果不指定，编译器无法给子类分配内存
* 如果想灵活指定出父类中T的类型，子类也需变为类模板
*/
#include<iostream>
#include<string>
#include <windows.h>
using namespace std;
template<class T>
class Base
{
    T m;

};
//class Son:public Base //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son :public Base<int>//必须指定一个类型
{};
void test01()
{
    Son c;
}
//类模板继承类模板， 可以用T2指定父类中的T类型
template<class T1, class  T2>
class Son2 :public Base<T2> // 定义一个名为Son2的类，继承自Base<T2>类
{
public:
    Son2() // 构造函数
    {
        cout << typeid(T1).name() << endl; // 输出T1的类型名
        cout << typeid(T2).name() << endl; // 输出T2的类型名
    }
};
void test02()
{
    Son2<int,char> child1;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    test01();
    test02();
	system("pause");
    return 0;
}
