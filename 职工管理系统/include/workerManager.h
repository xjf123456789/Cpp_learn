#pragma once
#include<iostream>
#include "worker.h"
#include <fstream>
#define  FILENAME "empFile.txt"
using namespace std;
class WorkerManager
{
public:


	//构造函数
	WorkerManager();
	void show_Menu();
	void save();//保存文件
	//统计人数
	int get_EmpNum();
	//析构函数
	~WorkerManager();
public:
	//记录文件中的人数个数
	int m_EmpNum;
	//增加职工
	void Add_Emp();
	//查找职工
	bool m_FileIsEmpty;
	//员工数组的指针
	Worker** m_EmpArray;
};
