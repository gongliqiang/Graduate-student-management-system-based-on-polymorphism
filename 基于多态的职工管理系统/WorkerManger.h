#pragma once //保证不会被包含多次
#include <iostream>
#include"Worker.h"
#include"Manger.h"
#include"employee.h"
#include"boss.h"
#include<fstream>
#define FILENAME "课题组.txt"

using namespace std;

class WorkerManger
{
public:
	//构造函数
	WorkerManger();
	//显示初始菜单函数
	void Showinit();
	//退出函数
	void ExitSystem();
	//纪录文件中成员人数个数
	int m_EmpNum;
	//员工数组的指针
	Worker**m_EmpArray;
	//增加成员函数
	void Add_Emp();
	//实现文件保存功能
	void save();
	//bool类型，用来判断是否已经存在文本文件
	bool m_FileIsEmpty;
	//当文件已经存在时获取已经纪录的成员
	int get_EmNum();
	//初始化数组
	void init_Emp();
	//显示职工
	void show_Emp();
	//删除员工
	void del_Emp();
	//根据员工编号判断编号是否存在
	int isExist(int id);
	//修改职工
	void mod_Emp();
	//查找职工
	void find_Emp();
	//员工排序函数
	void sort_Emp();
	//清空函数
	void clean_File();
	//析构函数
	~WorkerManger();




};