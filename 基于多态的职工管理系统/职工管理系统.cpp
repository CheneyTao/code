#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include "boss.h"
#include "manager.h"

using namespace std;
int main()
{
	/*Worker* worker = NULL;
	worker = new Employee(001, "����", 9527);
	worker->showInfo();
	cout << worker->getDeptName() << endl;
	
	
	worker = new Manager(2, "����",2);
	worker->showInfo();
	cout << worker->getDeptName() << endl;*/

    WorkerManager wm;
	
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "��������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:   //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:   //����Ա��
			wm.Add_Emp();
			break;
		case 2:   //��ʾԱ��
			wm.show_Emp();
			break;
		case 3:   //ɾ��Ա��
			wm.Del_Emp();
			break;
		case 4:   //�޸�Ա��
			wm.Mod_Emp();
			break;
		case 5:   //����Ա��
			wm.Find_Emp();
			break;
		case 6:   //����Ա��
			wm.Sort_Emp();
			break;
		case 7:   //����ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;

		}


	}
}