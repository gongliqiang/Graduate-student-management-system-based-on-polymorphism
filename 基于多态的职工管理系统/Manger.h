#pragma once
#include<iostream>
#include<string>
#include "Worker.h"//����������Դ����ļ���ͬ
using namespace std;
class Manger :public Worker {
public:
	//��ʼ�����캯��
	Manger(string name, int id, int did);
	//��̳У����ְλ����
	virtual string GetDeptName();
	//��ʾ������Ϣ
	virtual void Show_Name();


};