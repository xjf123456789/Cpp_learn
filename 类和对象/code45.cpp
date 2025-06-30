#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
//类的继承的基本语法
class BasePage
{
public:

	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
};
/*
继承的好处：==可以减少重复的代码==

class A : public B; 

A 类称为子类 或 派生类

B 类称为父类 或 基类 
*/
//Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java基础,Java进阶,SSM,SSH..." << endl;
	}
};
//Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python基础,Python进阶,Django,Tornado..." << endl;
	}
}
;

//C++页面
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "CPP基础,CPP进阶,QT,STL..." << endl;
	}
};
void test01()
{
	//Java页面
	cout << "Java下载视频页面如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python下载视频页面如下： " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;

	//C++页面
	cout << "C++下载视频页面如下： " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();
}
int main() {
	// 设置控制台编码为UTF-8
	SetConsoleOutputCP(CP_UTF8);
	
	test01();

	system("pause");

	return 0;
}