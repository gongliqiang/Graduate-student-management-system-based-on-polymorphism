#include"boss.h"

Boss::Boss(string name, int id, int did) {
	this->m_Name=name;
	this->m_ID=id;
	this->m_DID=did;
}
string Boss::GetDeptName() {
	return string("�ϰ�");
}
void Boss::Show_Name() {
	cout << "ְ�����ƣ�" << this->m_Name;
	cout << "\tְ����ţ�" << this->m_ID;
	cout << "\tְ�����ţ�" << this->GetDeptName();
	cout << "\t��λְ��Ŭ����������ѧ����ʹ����" << endl;
}