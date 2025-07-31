#include <vector>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std; 

void test01()
{
    string s1 = "hello";
    string s2 = "aello";

    int ret = s1.compare(s2);

	if (ret == 0) {
		cout << "s1 等于 s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 大于 s2" << endl;
	}
	else
	{
		cout << "s1 小于 s2" << endl;
	}
}
int main() {
    SetConsoleOutputCP(CP_UTF8);//解决中文乱码问题

	test01();

	system("pause");

	return 0;
}