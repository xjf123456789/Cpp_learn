#include "../include/workerManager.h"

WorkerManager::WorkerManager()
{
    cout << "WorkerManager 构造函数调用" << endl;
    	//初始化人数
	this->m_EmpNum = 0;

	//初始化数组指针
	this->m_EmpArray = NULL;
}
void WorkerManager::show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

WorkerManager::~WorkerManager()
{
    cout << "WorkerManager 析构函数调用" << endl;
}

// 增加职工
void WorkerManager::Add_Emp()
{
    cout << "增加职工信息功能" << endl;
    // 这里可以添加增加职工信息的具体实现
    int addNum;
    cin >> addNum;
    if(addNum >0)
    {
        //计算新空间的大小
        int newSiaze = this->m_EmpNum + addNum;//原来记录的人数 + 新增加的职工人数
        //开辟新空间
        Worker** newSpace = new Worker*[newSiaze];
    }
    


}