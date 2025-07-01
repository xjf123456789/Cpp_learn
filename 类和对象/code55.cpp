#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
/*
//普通实现
class Calculator {
public:
	int getResult(string oper)
	{
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
		//如果要提供新的运算，需要修改源码
	}
public:
	int m_Num1;
	int m_Num2;
};

void test01()
{
	//普通实现测试
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}
*/
//多态实现
/*
多态的优点：

* 代码组织结构清晰
* 可读性强
* 利于前期和后期的扩展以及维护
* 可以通过父类指针或引用来操作不同的子类对象
*/
class AbstractCalculator {
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
// 加法计算器
class AddCalculator : public AbstractCalculator 
{
public:
    virtual int getResult() override
    {
        return m_Num1 + m_Num2;
    }
};
// 减法计算器
class SubCalculator : public AbstractCalculator 
{
public:
    virtual int getResult() override
    {
        return m_Num1 - m_Num2;
    }

};
// 乘法计算器
class MulCalculator : public AbstractCalculator
{
public:
    virtual int getResult() override
    {
        return m_Num1 * m_Num2;
    }
};

// 多态：父类指针或引用指向子类对象（这里是父类指针）
void test01()
{
    //多态实现测试
    //创建加法计算器
    AbstractCalculator *calculator = new AddCalculator;
    calculator->m_Num1 = 10;
    calculator->m_Num2 = 10;
    cout << calculator->m_Num1 << " + " << calculator->m_Num2 << " = " << calculator->getResult() << endl;
    delete calculator;
    //创建减法计算器
    calculator = new SubCalculator;
    calculator->m_Num1 = 10;
    calculator->m_Num2 = 10;    
    cout << calculator->m_Num1 << " - " << calculator->m_Num2 << " = " << calculator->getResult() << endl;
    delete calculator;
    //创建乘法计算器
    calculator = new MulCalculator;
    calculator->m_Num1 = 10;
    calculator->m_Num2 = 10;
    cout << calculator->m_Num1 << " * " << calculator->m_Num2 << " = " << calculator->getResult() << endl;
    delete calculator;
}
int main() {
    // 设置控制台编码为UTF-8
    SetConsoleOutputCP(CP_UTF8);
 
    

    test01();
    
    system("pause");
    
    return 0;
}