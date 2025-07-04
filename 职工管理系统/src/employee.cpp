#include "../include/employee.h"
Employee::Employee(int id,string name,int dId)
{
    //this指针指向被调用的成员函数所属的对象
    this->m_Id = id; // 职工编号
    this->m_Name = name; // 职工姓名
    this->m_DeptId = dId; // 职工所在部门编号
}
void Employee::showInfo()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位编号：" << this->m_DeptId
         << endl;
}
string Employee::getDeptName()
{
    return string("员工"); 
}