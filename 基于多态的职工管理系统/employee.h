#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Employee :public Worker
{
public:
	//构造函数初始化
	Employee(string name, int id, int did);

	//获取职工岗位名称
	virtual string GetDeptName();//为啥有一个等于0
	//展示职工个人信息
	virtual void Show_Name();

};

