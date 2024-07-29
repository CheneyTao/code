#include "workerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//1.�ļ������ڣ������Խ��г�ʼ��
		//cout << "�ļ�������" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //ֱ�ӽ���������캯��
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�������
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //ֱ�ӽ���������캯��
	}
	//3.�ļ����ڲ��Ҽ�¼������         
	// ������Ҫ�ǰ��ļ��е����ݶ��뵽�ڴ�����Լ�ʹ�ļ��������ݣ���һ�δ�Ҳ��������Щ����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ " << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [num];
	this->init_Emp();
	//����
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ� " << this->m_EmpArray[i]->m_Id << " "
			<< "���� ��" << this->m_EmpArray[i]->m_Name << " "
			<< "ְλ��� ��" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��лʹ��" << endl;
	system("pause");
	exit(0);
}

//����Ա�����ļ���ʵ��
void WorkerManager::save()
{
	ofstream ofs;//д�ļ�
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�  --д�ļ�
	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();

}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ������
		num++;
	}
	ifs.close();
	return num;

}
//void WorkerManager::Show

//���ְ��
void WorkerManager:: Add_Emp()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker **newSpace = new Worker* [newSize];
		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i <addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "��Ա���ı�ţ�" << endl;
			cin >> id;			
			cout << "�������" << i + 1 << "��Ա����������" << endl;
			cin >> name;
			cout << "��ѡ��ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ�������浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray=newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		cout << "�ɹ����" <<addNum<<"����ְ��"<<endl ;
		this->save();


	}
	else 
	{
		cout << "������������" << endl;
	}
	    cout << "��������ص��ϲ�"<< endl;
//��������������ص��ϼ��˵�
		system("pause");
		system("cls");
}

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	int index = 0;
	int id;
	string name;
	int dId;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs>>dId)
	{
		Worker* worker;
		if (dId == 1)
			worker = new Employee(id, name, dId);
		else if (dId == 2)
			worker = new Manager(id, name, dId);
		else
			worker = new Boss(id,name, dId);

		this->m_EmpArray[index++] = worker;

	}
	ifs.close();
}

//��ʾ����Ա��
void WorkerManager::show_Emp()
{
	
		if (this->m_FileIsEmpty)
		{
			cout << "�ļ�Ϊ�գ����߲�����" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			this->m_EmpArray[i]->showInfo();
		}
		system("pause");
		system("cls");

}
//��ְ����Ų���ְ���Ƿ����
int  WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
			index = i;
	}
	return index;

}

//ɾ��Ա��
void  WorkerManager::Del_Emp()
{
	int index,tag;
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout <<"������Ҫɾ����Ա����" << endl;
		cin >> index;
		tag = IsExist(index);
		if (tag == -1)
		{
			cout << "�����ڸ�Ա��" << endl;
		}
		else
		{
			for (int i = tag; i < this->m_EmpNum - 1; i++)
		    {
			  this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		    }
			this->m_EmpNum--;
			this->save();
			cout<<" ɾ���ɹ� " << endl;
		}

	}
	system("pause");
	system("cls");
}

//�޸�Ա����Ϣ
void WorkerManager::Mod_Emp() 
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ����ļ�������" << endl;
	}
	else
	{
		cout<<"�������޸�Ա���ı�ţ�" << endl;
		int id,tag;
		cin >> id;
		tag = IsExist(id);
		if (tag == -1)
		{
			cout<<"Ա��������" << endl;
		}
		else
		{
			int id;
			string name;
			int dselect;
			cout << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "����ְ��������" << endl;
			cin >> name;		
			cout << "��ѡ��ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dselect;
			Worker* worker = NULL; 
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[tag] = worker;
			this->save();
			//delete worker;
			cout << "�޸ĳɹ�" << endl;
		}
	}
	system("pause");
	system("cls");

}


//����Ա��
void WorkerManager::Find_Emp()
{
	int flag = -1;
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else 
	{
		cout << "������ҵķ�ʽ" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;
		int select;
		cin >> select;
		if (select==1)
		{
			//����ְ����Ų���
			cout << "�����ѯ�ı�ţ�" << endl;
			int id;
			cin >> id;
			
			int tag = IsExist(id);
			if (tag == -1)
			{
				cout << "�����ڸ�ְ��" << endl;
			}
			else
			{
				this->m_EmpArray[tag]->showInfo();
			}
			
		}
		else if (select == 2)
		{
			//������������
			
			string name;
			cout << "��������ҵ�����" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					if (flag == -1)
					{
						cout << "���ҳɹ���������£�" << endl;
					}
					this->m_EmpArray[i]->showInfo();
					flag = 1;
				}
			}

		}

		else 
		{
			cout<<"�����д���,����������" << endl<<endl;
			this->Find_Emp();
		}
		if (flag == 1) 
		{
			cout << "��ѯ����" << endl;
		}
		else 
		{
			cout << "δ��ѯ�����" << endl;
		}
	}
	system("pause");
	system("cls");

}

//���������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "ѡ������ʽ��" << endl;
		cout << "1:��������" << endl;
		cout << "2:��������" << endl;
		int num;
		cin >> num;
		int m, tag;
		for (int i = 0; i < this->m_EmpNum - 1; i++)
		{
			tag = i;
			m = this->m_EmpArray[i]->m_Id;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (num == 1)
				{
					if (m > this->m_EmpArray[j]->m_Id)
					{
						m = this->m_EmpArray[j]->m_Id;
						tag = j;
					} 
				}
				else
				{
					if (m < this->m_EmpArray[j]->m_Id)
					{
						m = this->m_EmpArray[j]->m_Id;
						tag = j;
					}
				}

			}
			if (i != tag)
			{
				Worker* temp = NULL;
				temp = this->m_EmpArray[tag];
				this->m_EmpArray[tag] = this->m_EmpArray[i];
				this->m_EmpArray[i] = temp;
			}
			

		}
		cout << "����ɹ���" << endl;
		this->save();
		this->show_Emp();
	}
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
		}
	}

	system("pause");
	system("cls");
}

 WorkerManager::~WorkerManager()
{
	 if (this->m_EmpArray != NULL)
	 {
		 for (int i = 0; i < this->m_EmpNum; i++) 
		 {
			 if (this->m_EmpArray[i] != NULL)
			 {
				 delete this->m_EmpArray[i];
				 this->m_EmpArray[i] = NULL;
			 }
		 }
		 delete[] this->m_EmpArray;
		 this->m_EmpArray = NULL;
	 }
 }