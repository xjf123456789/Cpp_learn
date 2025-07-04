#pragma once
#include<iostream>
#include "worker.h"
using namespace std;
class WorkerManager
{
public:


	//构造函数
	WorkerManager();
	void show_Menu();

	//析构函数
	~WorkerManager();
public:
	//记录文件中的人数个数
	int m_EmpNum;
	//记录文件中的人数个数
	int m_EmpNum;
	//增加职工
	void Add_Emp();\
	//员工数组的指针
	Worker** m_EmpArray;
	//员工数组的指针
	Worker** m_EmpArray;
};
