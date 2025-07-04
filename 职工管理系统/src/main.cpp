#include "../include/workerManager.h"
#include <iostream>
#include <windows.h>
#include "../include/worker.h"
#include "../include/employee.h"
#include "../include/manager.h"
#include "../include/boss.h"


using namespace std;
void test()
{
    /*
    ✅ **Worker* 指针可以管理 Employee 的原因：**
    1. **继承关系**：Employee 是 Worker 的子类
    2. **向上转型**：子类对象可以安全地赋值给基类指针
    3. **多态性**：通过虚函数机制，基类指针调用的是实际对象的版本
    4. **统一接口**：所有员工类型都有相同的基本操作接口

这就是面向对象编程中**多态**的精髓：**一个接口，多种实现**！
    */
    Worker *worker = NULL;
    worker = new Employee(1,"张三",1);
    worker->showInfo();
    delete worker; // 释放内存
    worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}
int main() {
    // 设置控制台编码为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    // 创建 WorkerManager 对象
    // WorkerManager wm;
    // int choice = 0;
    // while(true)
    // {
    //     wm.show_Menu();
    //     cout <<"请输入您的选择："<<  endl;
    //     cin >> choice;
    //     switch(choice)
    //     {
    //         case 0:
    //             cout << "欢迎下次使用！" << endl;
    //             return 0; // 退出程序
    //         case 1:
    //             cout << "增加职工信息功能" << endl;
    //             // 调用增加职工信息的函数
    //             break;
    //         case 2:
    //             cout << "显示职工信息功能" << endl;
    //             // 调用显示职工信息的函数
    //             break;
    //         case 3:
    //             cout << "删除离职职工功能" << endl;
    //             // 调用删除离职职工的函数
    //             break;
    //         case 4:
    //             cout << "修改职工信息功能" << endl;
    //             // 调用修改职工信息的函数
    //             break;
    //         case 5:
    //             cout << "查找职工信息功能" << endl;
    //             // 调用查找职工信息的函数
    //             break;
    //         case 6:
    //             cout << "按照编号排序功能" << endl;
    //             // 调用排序的函数
    //             break;
    //         case 7:
    //             cout << "清空所有文档功能" << endl;
    //             // 调用清空文档的函数
    //             break;
    //         default:
    //             system("cls"); // 清屏
    //             break; // 无效输入，重新显示菜单
    //     }
    // }
    test();
    system("pause");
    return 0;
}
