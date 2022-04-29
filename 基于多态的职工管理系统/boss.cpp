#include"boss.h"

Boss::Boss(string name, int id, int did) {
	this->m_Name=name;
	this->m_ID=id;
	this->m_DID=did;
}
string Boss::GetDeptName() {
	return string("老板");
}
void Boss::Show_Name() {
	cout << "职工名称：" << this->m_Name;
	cout << "\t职工编号：" << this->m_ID;
	cout << "\t职工部门：" << this->GetDeptName();
	cout << "\t岗位职责：努力画饼，让学生们使劲干" << endl;
}