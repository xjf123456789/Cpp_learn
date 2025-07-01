/*
读文件步骤如下：
1. 包含头文件   
   \#include <fstream\>
2. 创建流对象  
   ifstream ifs;
3. 打开文件并判断文件是否打开成功
   ifs.open("文件路径",打开方式);
4. 读数据
   四种方式读取
5. 关闭文件
   ifs.close();
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void test01()
{
    // 读文件
    std::ifstream ifs;
    ifs.open("test.txt", std::ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << std::endl;
    }
    // //第一种方式
	// char buf[1024] = { 0 };
	// while (ifs >> buf)
	// {
	// 	cout << buf << endl;
	// }
    // //第二种方式
    // char buf[1024] = { 0 };
    // while(ifs.getline(buf, sizeof(buf)))  // getline函数读取
    // {
    //     cout << buf << endl;  // 这里每读取一行就换行
    // } 
    ////第三种方式
    // string buf;
    // while (getline(ifs, buf))
    // {
    //    cout << buf << endl;  // 这里每读取一行就换行
    // }
    
    //第四种方式 不太推荐
    char c;
    while ((c = ifs.get()) != EOF)  // get函数读取
    {
        cout << c;  // 这里每读取一个字符就输出
    }

    ifs.close();// 关闭文件
}
int main()
{
    test01();
    system("pause"); // 暂停程序，等待用户输入
    return 0;
}
/*
- 读文件可以利用 ifstream  ，或者fstream类
- 利用is_open函数可以判断文件是否打开成功
- close 关闭文件 
*/