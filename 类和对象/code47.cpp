#include<iostream>
#include <windows.h>
#include <string>
using namespace std;
class Base
{
    public:
    int m_A;
    protected:
    int m_B;
    private:
    int m_C;

};
//公共继承
class Son:public Base
{
public:
    int m_D;
};
void test01()
{
    cout << "sizeof(Son) = " << sizeof(Son) << endl;
}
int main()
{
    
    test01();
    system("pause");
    return 0;
    
}