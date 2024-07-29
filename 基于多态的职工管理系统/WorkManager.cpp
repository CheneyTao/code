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
		//1.文件不存在，对属性进行初始化
		//cout << "文件不存在" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //直接结束这个构造函数
	}
	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件读完了
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //直接结束这个构造函数
	}
	//3.文件存在并且记录了数据         
	// 这里主要是把文件中的数据读入到内存里，所以即使文件中有数据，第一次打开也可以用这些数据
	int num = this->get_EmpNum();
	cout << "职工人数为 " << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [num];
	this->init_Emp();
	//测试
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号： " << this->m_EmpArray[i]->m_Id << " "
			<< "姓名 ：" << this->m_EmpArray[i]->m_Name << " "
			<< "职位编号 ：" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "感谢使用" << endl;
	system("pause");
	exit(0);
}

//保存员工到文件的实现
void WorkerManager::save()
{
	ofstream ofs;//写文件
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件  --写文件
	//将每个人数据写入到文件中
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
		//统计人数
		num++;
	}
	ifs.close();
	return num;

}
//void WorkerManager::Show

//添加职工
void WorkerManager:: Add_Emp()
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker **newSpace = new Worker* [newSize];
		//将原来空间下的数据拷贝到新空间下
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
			cout << "请输入第" << i + 1 << "个员工的编号：" << endl;
			cin >> id;			
			cout << "请输入第" << i + 1 << "个员工的姓名：" << endl;
			cin >> name;
			cout << "请选择职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			//将创建职工，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有的空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray=newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		cout << "成功添加" <<addNum<<"名新职工"<<endl ;
		this->save();


	}
	else 
	{
		cout << "输入数据有误" << endl;
	}
	    cout << "任意键，回到上层"<< endl;
//按任意键后清屏回到上级菜单
		system("pause");
		system("cls");
}

//初始化员工
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

//显示所有员工
void WorkerManager::show_Emp()
{
	
		if (this->m_FileIsEmpty)
		{
			cout << "文件为空，或者不存在" << endl;
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
//按职工编号查找职工是否存在
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

//删除员工
void  WorkerManager::Del_Emp()
{
	int index,tag;
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout <<"输入需要删除的员工号" << endl;
		cin >> index;
		tag = IsExist(index);
		if (tag == -1)
		{
			cout << "不存在该员工" << endl;
		}
		else
		{
			for (int i = tag; i < this->m_EmpNum - 1; i++)
		    {
			  this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		    }
			this->m_EmpNum--;
			this->save();
			cout<<" 删除成功 " << endl;
		}

	}
	system("pause");
	system("cls");
}

//修改员工信息
void WorkerManager::Mod_Emp() 
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者文件不存在" << endl;
	}
	else
	{
		cout<<"请输入修改员工的编号：" << endl;
		int id,tag;
		cin >> id;
		tag = IsExist(id);
		if (tag == -1)
		{
			cout<<"员工不存在" << endl;
		}
		else
		{
			int id;
			string name;
			int dselect;
			cout << "输入职工编号：" << endl;
			cin >> id;
			cout << "输入职工姓名：" << endl;
			cin >> name;		
			cout << "请选择职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			cout << "修改成功" << endl;
		}
	}
	system("pause");
	system("cls");

}


//查找员工
void WorkerManager::Find_Emp()
{
	int flag = -1;
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else 
	{
		cout << "输入查找的方式" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;
		int select;
		cin >> select;
		if (select==1)
		{
			//按照职工编号查找
			cout << "输入查询的编号：" << endl;
			int id;
			cin >> id;
			
			int tag = IsExist(id);
			if (tag == -1)
			{
				cout << "不存在该职工" << endl;
			}
			else
			{
				this->m_EmpArray[tag]->showInfo();
			}
			
		}
		else if (select == 2)
		{
			//按照姓名查找
			
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					if (flag == -1)
					{
						cout << "查找成功，结果如下：" << endl;
					}
					this->m_EmpArray[i]->showInfo();
					flag = 1;
				}
			}

		}

		else 
		{
			cout<<"输入有错误,请重新输入" << endl<<endl;
			this->Find_Emp();
		}
		if (flag == 1) 
		{
			cout << "查询结束" << endl;
		}
		else 
		{
			cout << "未查询到结果" << endl;
		}
	}
	system("pause");
	system("cls");

}

//按编号排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "选择排序方式：" << endl;
		cout << "1:升序排序" << endl;
		cout << "2:降序排序" << endl;
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
		cout << "排序成功：" << endl;
		this->save();
		this->show_Emp();
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
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