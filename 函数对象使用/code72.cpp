/*
* 返回bool类型的仿函数称为**谓词**
* 如果operator()接受一个参数，那么叫做一元谓词
* 如果operator()接受两个参数，那么叫做二元谓词
*/
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <windows.h>
#include <algorithm>

struct GreaterFive
{
    bool operator()(int val)
    {
        return val >5;
    }
};

void test01()
{
    vector<int> v;
    for(int i = 0; i<10;i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
    if(it == v.end())
    {
        	cout << "没找到!" << endl;
    }
	else {
		cout << "找到:" << *it << endl;
	}
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

	test01();

	system("pause");

	return 0;
}