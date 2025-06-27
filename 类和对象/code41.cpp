/*
* 递增运算符重载
*/


#include <iostream>
using namespace std;
//          
class MyInteger {
    friend ostream& operator<<(ostream& out, const MyInteger& myint);
public:
    MyInteger()
    {
        m_Num = 0;
    }
    //前置++
    MyInteger& operator++()
    {
        //先自增再返回
        m_Num++;
        return *this;
    }
    //后置++
    MyInteger operator++(int)
    {
        //先返回当前值再自增
        MyInteger temp = *this; //保存当前值；然后让本身加1
        m_Num++;
        return temp;
    }
private:
    int m_Num;
};
// 重载输出运算符
ostream& operator<<(ostream& out, const MyInteger& myint)
{
    out << myint.m_Num;
    return out;
}
//前置++ 先++ 再返回
void test01() 
{
    MyInteger myint;
    cout << ++myint << endl; // 输出
    cout << myint << endl; // 输出	
}
//后置++ 先返回当前值再++
void test02()
{
    MyInteger myint;
    cout << myint++ << endl; // 输出
    cout << myint << endl; // 输出
}
int main()
{
    test01(); // 测试前置++
    test02(); // 测试后置++
    return 0;
}
