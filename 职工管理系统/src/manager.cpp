#include "../include/manager.h"
Manager::Manager(int id, string name, int dId)
{
    // this指针指向被调用的成员函数所属的对象
    this->m_Id = id; // 职工编号
    this->m_Name = name; // 职工姓名
    this->m_DeptId = dId; // 职工所在部门编号
}
void Manager::showInfo()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位编号：" << this->m_DeptId
         << endl;
}
string Manager::getDeptName()
{
    return string("经理");
}