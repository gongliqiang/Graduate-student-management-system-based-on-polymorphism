#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	//获取职工岗位名称
	virtual string GetDeptName()=0;
	//展示职工个人信息
	virtual void Show_Name()=0;
	//职工名称
	string m_Name;
	//职工编号
	int m_ID;
	//职工部门
	int m_DID;
};
