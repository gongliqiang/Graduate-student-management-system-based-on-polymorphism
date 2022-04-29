#pragma once
#include<iostream>
#include<string>
#include "Worker.h"//这里与调用自带库文件不同
using namespace std;
class Manger :public Worker {
public:
	//初始化构造函数
	Manger(string name, int id, int did);
	//虚继承，获得职位名称
	virtual string GetDeptName();
	//显示个人信息
	virtual void Show_Name();


};