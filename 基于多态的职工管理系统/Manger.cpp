#include"Manger.h"

//���캯��
Manger::Manger(string name, int id, int did) {
	this->m_Name=name;
	this->m_ID=id;
	this->m_DID=did;
}
string Manger::GetDeptName() {
	return string("С�ϰ�");
}

 void Manger::Show_Name() {
	cout << "ְ�����ƣ�" << this->m_Name;
	cout << "\tְ����ţ�" << this->m_ID;
	cout << "\tְ�����ţ�" << this->GetDeptName();
	cout << "\t��λְ�𣺲�Ҫ���Ÿ��ϰ���Ÿ�" << endl;
}