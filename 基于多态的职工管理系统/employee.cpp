//普通员工
#include "employee.h"
//using namespace std;

//构造函数
Employee::Employee(string name, int id, int did)
{
	this->m_Name=name;//不同成员函数调用同一个数据时，通过this指针跳转到成员函数所指定的值
	this->m_ID=id;
	this->m_DID=did;
}

void Employee::Show_Name()
{
	cout << "职工名称：" << this->m_Name;
	cout << "\t职工编号：" << this->m_ID;
	cout << "\t职工部门：" << this->GetDeptName();
	cout << "\t岗位职责：服从经理的安排" << endl;
}

string Employee::GetDeptName()
{
	return string("员工");
}