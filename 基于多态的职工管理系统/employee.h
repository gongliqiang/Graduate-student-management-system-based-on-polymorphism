#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Employee :public Worker
{
public:
	//���캯����ʼ��
	Employee(string name, int id, int did);

	//��ȡְ����λ����
	virtual string GetDeptName();//Ϊɶ��һ������0
	//չʾְ��������Ϣ
	virtual void Show_Name();

};

