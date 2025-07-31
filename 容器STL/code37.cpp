#include <vector>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
/*
**功能描述：**
* 减少vector在动态扩展容量时的扩展次数

**函数原型：**
* `reserve(int len);`//容器预留len个元素长度，预留位置不初始化，元素不可访问。
总结：如果数据量较大，可以一开始利用reserve预留空间
*/
void test01()
{
    vector<int> v;
    int num =0;
    int *p = NULL;
    //预留空间
	v.reserve(100000);

    //记录写入10000个元素到底开辟了多少次内存
    for(int i = 0;i<100000;i++)
    {
        v.push_back(i);
        if(p != &v[0])
        {
           p = &v[0];
           num++; 
        }
    }
    cout << "num =" << num << endl;
}
int main()
{
	SetConsoleOutputCP(CP_UTF8);

	test01();


	system("pause");
	return 0;
    
}