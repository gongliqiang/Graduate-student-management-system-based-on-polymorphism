#include"WorkerManger.h"


WorkerManger::WorkerManger()
{
	//���ļ�
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ������ڵ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ��
		this->m_EmpArray = NULL;//��ʼ������
		ifs.close();
		return;//??
	}
	//�ļ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ��
		this->m_EmpArray = NULL;//��ʼ������
		ifs.close();
		return;//??
	}
	int num = this->get_EmNum();
	//cout << "ְ������" << num << endl;//���Դ���
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	init_Emp();
	//���Դ���
	/*for (int i = 0; i < m_EmpNum; i++) {
		cout << "����" << this->m_EmpArray[i]->m_Name
			<< "ѧ��" << this->m_EmpArray[i]->m_ID
			<< "ְλ" << this->m_EmpArray[i]->m_DID<<endl;

	}*/


};


//��ʾ��ʼ���˵�
void WorkerManger::Showinit()
{
	cout << "********************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ�� **********" << endl; 
	cout << "************* 0.�˳�������� *************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl; 
	cout << "************* 2.��ʾְ����Ϣ *************" << endl; 
	cout << "************* 3.ɾ����ְְ�� *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl; 
	cout << "************* 5.����ְ����Ϣ *************" << endl; 
	cout << "************* 6.���ձ������ *************" << endl; 
	cout << "************* 7.��������ĵ� *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
};
void WorkerManger::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);

};
void WorkerManger::Add_Emp()
{
	cout << "�������������о���������" << endl;//��һ�²�Ҫendl
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		//�����¿ռ�Ĵ�С
		int newsize = this->m_EmpNum + addNum;
		//���ٶ������µ�����
		Worker**newSpace = new Worker*[newsize];//�µ�Worker���ָ����newsize����Worker���ָ���ָ�����ʼ��ַ��newSpace
		//��֮ǰ�����ݴ�����
		if (this->m_EmpArray != NULL) {//���캯�����ʼ���ˣ�����֮��Ͳ�����Null
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�����µ�����
		for (int i = 0; i < addNum; i++) {
			string name;
			int id;
			int dSelect;
			cout << "�����������ĵ�" << i + 1 << "��Ա������" << endl;
			cin >> name;
			cout << "�����������ĵ�" << i + 1 << "��Ա��ѧ��" << endl;
			cin >> id;
			cout << "��ѡ����������ͣ�" << endl;
			cout << "1���ϰ�" << endl;
			cout << "2��С�ϰ�" << endl;
			cout << "3���о���" << endl;
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
		//�ͷ�ԭ���Ŀռ�
		delete[] this->m_EmpArray;
		//�����µĿռ�
		this->m_EmpArray = newSpace;
		//�����µĸ���
		this->m_EmpNum = newsize;
		//��¼�ļ��Ѿ�����
		this->m_FileIsEmpty = false;
		//��ʾ��Ϣ
		cout << "��ӳɹ�" << addNum<<"��������You are good!"<<endl;
		//�����ļ�
		this->save();

		
	}
	else
	{
		cout << "���������������������" << endl;
	}
	//�˳�����
	system("pause");
	system("clc");
}

void WorkerManger::save() {
	//д�ļ���ʽ
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Name << " "
		 << this->m_EmpArray[i]->m_ID << " "
		 << this->m_EmpArray[i]->m_DID << endl;
	}
	ofs.close();
}
//���ְ������
int WorkerManger::get_EmNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string name;
	int id;
	int did;

	int num = 0;
	while (ifs >> name && ifs >> id && ifs >> did) {
		//��¼����
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {
			for (int i = index; i < m_EmpNum-1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "�����ڴ˱��ְ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա�����" << endl;
		int id = 0;
		cin >> id;
		int ret = this->isExist(id);
		if (ret!= -1) {
			delete this->m_EmpArray[ret];
			string newName="";
			int newId = 0;
			int newDid = 0;
			cout << "�鵽" << id << "ְ������������ְ����" << endl;
			cin >> newId;
			cout << "����������" << endl;
			cin >> newName;
			cout << "��ѡ��ְλ" << endl;
			cout << "1���ϰ�" << endl;
			cout << "2��С�ϰ�" << endl;
			cout << "3���о���" << endl;
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
			cout << "�޸ĳɹ�" << endl;
			this->save();
			
		}
		else {
			cout << "�����ڴ˱��ְ��" << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManger::find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int fselect=0;
		cout << "��ѡ����ҷ�ʽ" << endl;
		cout << "1������Ų���" << endl;
		cout << "2�������ֲ���" << endl;
		
		cin >> fselect;
		if (fselect == 1) {
			int id = 0;
			cout << "��������" << endl;
			cin >> id;
			int ret = this->isExist(id);
			if (ret != -1) {
				cout << "�鵽���Ϊ" << id << "��Ա����ϢΪ" << endl;
				this->m_EmpArray[ret]->Show_Name();
			}
			else
			{
				cout << "�����ڸ�Ա��" << endl;
			}
		}
		else if (fselect == 2) {
			string name = "";
			bool flag = false;
			cout << "������Ա��������" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "�鵽Ա��" << name << "Ա����Ϣ����" << endl;
					this->m_EmpArray[i]->Show_Name();
					flag = true;
				}
				
			}
			if (flag == false) {
				cout << "�����ڸ�Ա��" << endl;
			}
		}
		else {
			cout << "�������������䣡" << endl;
		}
		
		

	}
	system("pause");
	system("cls");
}

void WorkerManger::sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "����ɹ���������Ϊ��" << endl;
		this->save();
		this->show_Emp();
	}
}

void WorkerManger::clean_File() {
	int select = 0;
	cout << "�Ƿ�ȷ��ɾ��" << endl;
	cout << "1��ȷ��ɾ��" << endl;
	cout << "2�����ز˵�" << endl;
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
		cout << "ɾ���ļ��ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManger::~WorkerManger()
{
	//����ͷŶ�������
	if (m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
};


