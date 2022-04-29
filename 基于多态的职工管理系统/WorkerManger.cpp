#include"WorkerManger.h"


WorkerManger::WorkerManger()
{
	//读文件
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在的情况
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_FileIsEmpty = true;//初始化文件为空
		this->m_EmpArray = NULL;//初始化数组
		ifs.close();
		return;//??
	}
	//文件存在为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_FileIsEmpty = true;//初始化文件为空
		this->m_EmpArray = NULL;//初始化数组
		ifs.close();
		return;//??
	}
	int num = this->get_EmNum();
	//cout << "职工个数" << num << endl;//测试代码
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	init_Emp();
	//测试代码
	/*for (int i = 0; i < m_EmpNum; i++) {
		cout << "姓名" << this->m_EmpArray[i]->m_Name
			<< "学号" << this->m_EmpArray[i]->m_ID
			<< "职位" << this->m_EmpArray[i]->m_DID<<endl;

	}*/


};


//显示初始化菜单
void WorkerManger::Showinit()
{
	cout << "********************************************" << endl;
	cout << "********* 欢迎使用职工管理系统！ **********" << endl; 
	cout << "************* 0.退出管理程序 *************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl; 
	cout << "************* 2.显示职工信息 *************" << endl; 
	cout << "************* 3.删除离职职工 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl; 
	cout << "************* 5.查找职工信息 *************" << endl; 
	cout << "************* 6.按照编号排序 *************" << endl; 
	cout << "************* 7.清空所有文档 *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
};
void WorkerManger::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);

};
void WorkerManger::Add_Emp()
{
	cout << "请输入新增加研究生数量：" << endl;//试一下不要endl
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		//计算新空间的大小
		int newsize = this->m_EmpNum + addNum;
		//开辟堆区给新的数据
		Worker**newSpace = new Worker*[newsize];//新的Worker类的指针有newsize个，Worker类的指针的指针的起始地址是newSpace
		//把之前的数据传进来
		if (this->m_EmpArray != NULL) {//构造函数里初始化了，新增之后就不等于Null
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//输入新的数据
		for (int i = 0; i < addNum; i++) {
			string name;
			int id;
			int dSelect;
			cout << "请输入新增的第" << i + 1 << "个员工姓名" << endl;
			cin >> name;
			cout << "请输入新增的第" << i + 1 << "个员工学号" << endl;
			cin >> id;
			cout << "请选择输入的类型：" << endl;
			cout << "1、老板" << endl;
			cout << "2、小老板" << endl;
			cout << "3、研究生" << endl;
			cin >> dSelect;
			Worker*worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Boss(name, id, 1);
				break;
			case 2:
				worker = new Manger(name, id, 2);
			case 3:
				worker = new Employee(name, id, 3);
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原来的空间
		delete[] this->m_EmpArray;
		//更新新的空间
		this->m_EmpArray = newSpace;
		//更新新的个数
		this->m_EmpNum = newsize;
		//纪录文件已经存在
		this->m_FileIsEmpty = false;
		//提示信息
		cout << "添加成功" << addNum<<"名劳力，You are good!"<<endl;
		//保存文件
		this->save();

		
	}
	else
	{
		cout << "输入错误，请输入正整数！" << endl;
	}
	//退出清屏
	system("pause");
	system("clc");
}

void WorkerManger::save() {
	//写文件方式
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Name << " "
		 << this->m_EmpArray[i]->m_ID << " "
		 << this->m_EmpArray[i]->m_DID << endl;
	}
	ofs.close();
}
//获得职工数量
int WorkerManger::get_EmNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string name;
	int id;
	int did;

	int num = 0;
	while (ifs >> name && ifs >> id && ifs >> did) {
		//纪录人数
		num++;
	}
	ifs.close();
	return num;

}
void WorkerManger::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	int did;
	string name;
	int index = 0;
	while (ifs >> name && ifs >> id && ifs >> did) {
		Worker*worker = NULL;
		if (did == 1) {
			worker = new Boss(name, id, did);
		}
		else if (did == 2) {
			worker = new Manger(name, id, did);
		}
		else
		{
			worker = new Employee(name, id, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManger::show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或纪录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++) {
			this->m_EmpArray[i]->Show_Name();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManger::del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或纪录为空" << endl;
	}
	else
	{
		cout << "请输入要删除的员工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {
			for (int i = index; i < m_EmpNum-1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "不存在此编号职工" << endl;
		}
		
	}
	system("pause");
	system("cls");
}

int WorkerManger::isExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManger::mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或纪录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的员工编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->isExist(id);
		if (ret!= -1) {
			delete this->m_EmpArray[ret];
			string newName="";
			int newId = 0;
			int newDid = 0;
			cout << "查到" << id << "职工，请输入新职工号" << endl;
			cin >> newId;
			cout << "请输入姓名" << endl;
			cin >> newName;
			cout << "请选择职位" << endl;
			cout << "1、老板" << endl;
			cout << "2、小老板" << endl;
			cout << "3、研究生" << endl;
			cin >> newDid;
			Worker*worker = NULL;
			switch (newDid)
			{
			case 1:
				worker = new Boss(newName, newId, 1);
				break;
			case 2:
				worker = new Manger(newName, newId, 2);
			case 3:
				worker = new Employee(newName, newId, 3);
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			this->save();
			
		}
		else {
			cout << "不存在此编号职工" << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManger::find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或纪录为空" << endl;
	}
	else
	{
		int fselect=0;
		cout << "请选择查找方式" << endl;
		cout << "1、按编号查找" << endl;
		cout << "2、按名字查找" << endl;
		
		cin >> fselect;
		if (fselect == 1) {
			int id = 0;
			cout << "请输入编号" << endl;
			cin >> id;
			int ret = this->isExist(id);
			if (ret != -1) {
				cout << "查到编号为" << id << "的员工信息为" << endl;
				this->m_EmpArray[ret]->Show_Name();
			}
			else
			{
				cout << "不存在该员工" << endl;
			}
		}
		else if (fselect == 2) {
			string name = "";
			bool flag = false;
			cout << "请输入员工姓名：" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "查到员工" << name << "员工信息如下" << endl;
					this->m_EmpArray[i]->Show_Name();
					flag = true;
				}
				
			}
			if (flag == false) {
				cout << "不存在该员工" << endl;
			}
		}
		else {
			cout << "输入有误请重输！" << endl;
		}
		
		

	}
	system("pause");
	system("cls");
}

void WorkerManger::sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或纪录为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int maxIndex = i;
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (this->m_EmpArray[maxIndex]->m_ID >this->m_EmpArray[j]->m_ID) {
					maxIndex = j ;

				}
			}
			if (i != maxIndex) {
				Worker*temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[maxIndex];
				this->m_EmpArray[maxIndex] = temp;
			}
		}
		cout << "排序成功，排序结果为：" << endl;
		this->save();
		this->show_Emp();
	}
}

void WorkerManger::clean_File() {
	int select = 0;
	cout << "是否确认删除" << endl;
	cout << "1、确认删除" << endl;
	cout << "2、返回菜单" << endl;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];

				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "删除文件成功" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManger::~WorkerManger()
{
	//最后释放堆区数据
	if (m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
};


