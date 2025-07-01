#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
/*
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构**

虚析构和纯虚析构共性：
* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构区别：
* 如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法：
virtual ~类名(){}

纯虚析构语法：
virtual ~类名() = 0;
类名::~类名(){}(类外实现)
*/
class Animal {
public:
    Animal()
    {
        cout << "Animal 构造函数调用！" << endl;
    }
    //析构函数加上virtual关键字,变成析构函数
    virtual void speak() = 0;
    virtual ~Animal()
    {
        cout << "Animal 析构函数调用！" << endl;
    }
};
//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
class Cat : public Animal 
{
public:
    Cat(string name)
    {
        cout << "Cat 构造函数调用！" << endl;
        m_Name = new string(name);
    }
    virtual void speak() override
    {
        cout << "喵喵喵！" << endl;
    }
    ~Cat()
    {
        cout << "Cat 析构函数调用！" << endl;
        if(this->m_Name != NULL) // 检查指针是否为NULL
        delete m_Name; // 释放堆区内存
        m_Name = NULL; // 避免悬空指针
    }
public:
    string* m_Name; // 指针成员变量，指向堆区内存
};
void test01()
{
    Animal *animal = new Cat("小花猫");
    animal->speak();
	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}
int main() {
    // 设置控制台编码为UTF-8
	SetConsoleOutputCP(CP_UTF8);
    test01();
    system("pause");
    return 0;
}
