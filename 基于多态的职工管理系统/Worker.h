#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	//��ȡְ����λ����
	virtual string GetDeptName()=0;
	//չʾְ��������Ϣ
	virtual void Show_Name()=0;
	//ְ������
	string m_Name;
	//ְ�����
	int m_ID;
	//ְ������
	int m_DID;
};
