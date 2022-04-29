#include"Manger.h"

//构造函数
Manger::Manger(string name, int id, int did) {
	this->m_Name=name;
	this->m_ID=id;
	this->m_DID=did;
}
string Manger::GetDeptName() {
	return string("小老板");
}

 void Manger::Show_Name() {
	cout << "职工名称：" << this->m_Name;
	cout << "\t职工编号：" << this->m_ID;
	cout << "\t职工部门：" << this->GetDeptName();
	cout << "\t岗位职责：不要明着跟老板对着干" << endl;
}