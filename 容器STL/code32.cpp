/*
**功能描述：**
* 给vector容器进行赋值

**函数原型：**
* vector& operator=(const vector &vec);//重载等号操作符
* assign(beg, end);       //将[beg, end)区间中的数据拷贝赋值给本身。
* assign(n, elem);       //将n个elem拷贝赋值给本身。
*/


#include <vector>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void printvector(vector<int>& v)
{
    for(vector<int>::iterator it = v.begin();it != v.end(); it++)
    {
        cout << *it << " ";

    }
    cout << endl;
}

void test01()
{
    vector<int> v1;//无参构造
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);

    vector<int> v2;
    v2 =v1;
    printvector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printvector(v3);

    vector<int> v4;
    v4.assign(10,100);
    printvector(v4);
}
int main() {

	test01();

	system("pause");

	return 0;
}