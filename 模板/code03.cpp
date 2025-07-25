#include<iostream>
#include<string>
#include <windows.h>
using namespace std;
//函数模板注意事项
//1.自动类型推导，必须是推导出一致的数据类型T才可以使用
//2.模板必须要确定出T的数据类型，才可以使用
template <typename T> //typename可以替换成class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
//1.自动类型推导，必须是推导出一致的数据类型T才可以使用
void test01()
{
    int a = 10;
    int b = 20;
    mySwap(a, b);
    cout << "a = " << a << ", b = " << b << endl; // 输出：a = 20, b = 10
}
//2.模板必须要确定出T的数据类型，才可以使用
template <typename T>
void func()
{
    cout << "func函数的调用" << endl;
}


void test02()
{
    // func();  无法自动推导
    func<int>(); // 显式指定类型
    cout << "test02函数的调用" << endl;
}
int main() {
    // 设置控制台编码为UTF-8
	SetConsoleOutputCP(CP_UTF8);
	// 调用系统命令，暂停程序运行，等待用户按下任意键继续
	
    test01();
    test02();
	// 返回0，表示程序正常结束
    system("pause");
	return 0;
}