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
		cout << "������������: ";
		cin >> chioce;
		
		switch (chioce)
		{
		case 0://�˳�ϵͳ����
			wm.ExitSystem();
			break;
		case 1://����ְ������
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.del_Emp();
			break;
		case 4://�޸�ְ��
			wm.mod_Emp();
			break;
		case 5://����Ա��
			wm.find_Emp();
			break;
		case 6://��������Ա��
			wm.sort_Emp();
			break;
		case 7://����ļ�
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
	//���Դ���
	Worker*worker = NULL;
	//����һ����ָ�� ԭ������newһ����ָ���ʱ��������ɹ�����NULL����Ұָ����ɳ������
	worker = new Employee("����ǿ", 2, 1);
	worker->Show_Name();
	delete worker;

	worker = new Manger("����ǿ", 2, 1);
	worker->Show_Name();
	delete worker;

	worker = new Boss("����ǿ", 2, 1);
	worker->Show_Name();
	delete worker;


}