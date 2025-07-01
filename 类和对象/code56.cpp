#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
class Base
{
public:
	//纯虚函数
	//类中只要有一个纯虚函数就称为抽象类
	//抽象类无法实例化对象
	//子类必须重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};

class Son : public Base
{
public:
    //重写父类中的纯虚函数
    virtual void func() override
    {
        cout << "Son 重写了 Base 的 func 函数" << endl;
    }
};
void test01()
{
	Base * base = NULL;
	//base = new Base; // 错误，抽象类无法实例化对象
	base = new Son;
	base->func();
	delete base;//记得销毁
}
int main()
{
    // 设置控制台编码为UTF-8
    SetConsoleOutputCP(CP_UTF8);
	test01();
	system("pause");
	return 0;

}