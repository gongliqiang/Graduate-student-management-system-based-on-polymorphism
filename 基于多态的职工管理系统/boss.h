#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;
class Boss :public Worker {
public:
	Boss(string name, int id, int did);
	virtual string GetDeptName();
	virtual void Show_Name();
};
