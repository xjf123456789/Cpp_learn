/*
**功能描述：**
* 对vector中的数据的存取操作

**函数原型：**
* at(int idx);      //返回索引idx所指的数据
* operator[];       //返回索引idx所指的数据
* front();          //返回容器中第一个数据元素
* back();           //返回容器中最后一个数据元素
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void test01()
{
    vector<int>v1;
    for(int i= 0; i<10; i++)
    {
        v1.push_back(i);
    }

    for(int i = 0; i<v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "v1的第一个元素为:"   << v1.front() <<endl;
    cout << "v1的最后一个元素为:" << v1.back()  <<endl;


}


int main()
{
    SetConsoleOutputCP(CP_UTF8);

    test01();

	system("pause");

	return 0;
}