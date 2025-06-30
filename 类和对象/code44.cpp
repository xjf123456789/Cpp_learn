#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
class MyPrint
{
public:
    void operator()(string str)
    {
        cout << str << endl;
    }
};
void test01()
{
    MyPrint myPrint;
    myPrint("hello world");
}
class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};
void test02()
{
    MyAdd myAdd;
    int ret = myAdd(10, 20);
    cout << "ret = " << ret << endl;
    //匿名对象调用;调用完立即释放e
    cout << "MyAdd()(10,20) = " << MyAdd()(10, 20) << endl;
}
int main()
{
    // 调用test01函数
    test01();   
    // 调用test02函数
    test02();
    // 暂停程序，等待用户按下任意键
    system("pause");
    // 返回0，表示程序正常结束
    return 0;
}