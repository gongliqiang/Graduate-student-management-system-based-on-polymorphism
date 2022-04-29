#include<iostream>
using namespace std;
#include "WorkerManger.h"
#include"Worker.h"
#include"employee.h"
#include"Manger.h"
#include"boss.h"
void test();
int main()
{
	/*test();*/
	int chioce = 0;
	WorkerManger wm;
	while (true)
	{
		wm.Showinit();
		cout << "请输入操作序号: ";
		cin >> chioce;
		
		switch (chioce)
		{
		case 0://退出系统操作
			wm.ExitSystem();
			break;
		case 1://增加职工操作
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.mod_Emp();
			break;
		case 5://查找员工
			wm.find_Emp();
			break;
		case 6://升序排序员工
			wm.sort_Emp();
			break;
		case 7://清空文件
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
void test() {
	//测试代码
	Worker*worker = NULL;
	//创建一个空指针 原因：下面new一个新指针的时候，如果不成功不是NULL会变成野指针造成程序崩溃
	worker = new Employee("巩利强", 2, 1);
	worker->Show_Name();
	delete worker;

	worker = new Manger("巩利强", 2, 1);
	worker->Show_Name();
	delete worker;

	worker = new Boss("巩利强", 2, 1);
	worker->Show_Name();
	delete worker;


}