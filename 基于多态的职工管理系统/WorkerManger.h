#pragma once //��֤���ᱻ�������
#include <iostream>
#include"Worker.h"
#include"Manger.h"
#include"employee.h"
#include"boss.h"
#include<fstream>
#define FILENAME "������.txt"

using namespace std;

class WorkerManger
{
public:
	//���캯��
	WorkerManger();
	//��ʾ��ʼ�˵�����
	void Showinit();
	//�˳�����
	void ExitSystem();
	//��¼�ļ��г�Ա��������
	int m_EmpNum;
	//Ա�������ָ��
	Worker**m_EmpArray;
	//���ӳ�Ա����
	void Add_Emp();
	//ʵ���ļ����湦��
	void save();
	//bool���ͣ������ж��Ƿ��Ѿ������ı��ļ�
	bool m_FileIsEmpty;
	//���ļ��Ѿ�����ʱ��ȡ�Ѿ���¼�ĳ�Ա
	int get_EmNum();
	//��ʼ������
	void init_Emp();
	//��ʾְ��
	void show_Emp();
	//ɾ��Ա��
	void del_Emp();
	//����Ա������жϱ���Ƿ����
	int isExist(int id);
	//�޸�ְ��
	void mod_Emp();
	//����ְ��
	void find_Emp();
	//Ա��������
	void sort_Emp();
	//��պ���
	void clean_File();
	//��������
	~WorkerManger();




};