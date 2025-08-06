/*
**功能描述：**
* 成对出现的数据，利用对组可以返回两个数据

**两种创建方式：**
* `pair<type, type> p ( value1, value2 );`
* `pair<type, type> p = make_pair( value1, value2 );`
*/

#include <set>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

//对组创建
void test01()
{
     pair<string, int> p(string("Tom"),20);
     cout << "姓名: " << p.first << "年龄: " << p.second << endl;

     pair<string, int> p2 = make_pair("Jerry",10);
     cout << "姓名：" << p2.first <<"年龄："<<p2.second << endl;


}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    test01();
    system("pause");
    return 0;

}