//��ͨԱ��
#include "employee.h"
//using namespace std;

//���캯��
Employee::Employee(string name, int id, int did)
{
	this->m_Name=name;//��ͬ��Ա��������ͬһ������ʱ��ͨ��thisָ����ת����Ա������ָ����ֵ
	this->m_ID=id;
	this->m_DID=did;
}

void Employee::Show_Name()
{
	cout << "ְ�����ƣ�" << this->m_Name;
	cout << "\tְ����ţ�" << this->m_ID;
	cout << "\tְ�����ţ�" << this->GetDeptName();
	cout << "\t��λְ�𣺷��Ӿ���İ���" << endl;
}

string Employee::GetDeptName()
{
	return string("Ա��");
}