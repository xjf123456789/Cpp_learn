/*

操作文件的三大类:
1. ofstream：写操作
2. ifstream： 读操作
3. fstream ： 读写操作
   
写文件步骤如下：
1. 包含头文件   
   \#include <fstream\>
2. 创建流对象  
   ofstream ofs;
3. 打开文件
   ofs.open("文件路径",打开方式);
4. 写数据
   ofs << "写入的数据";
5. 关闭文件
    ofs.close();


| 打开方式    | 解释                       |
| ----------- | -------------------------- |
| ios::in     | 为读文件而打开文件         |
| ios::out    | 为写文件而打开文件         |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在先删除，再创建 |
| ios::binary | 二进制方式                 |


*/
#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
    // 写文件
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "name:Tom" << endl;
    ofs << "age:18" << endl;
    ofs.close();
}

int main()
{
    test01();
    system("pause"); // 暂停程序，等待用户输入
    return 0;
}