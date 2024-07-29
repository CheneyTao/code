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
	worker = new Employee(001, "王五", 9527);
	worker->showInfo();
	cout << worker->getDeptName() << endl;
	
	
	worker = new Manager(2, "李四",2);
	worker->showInfo();
	cout << worker->getDeptName() << endl;*/

    WorkerManager wm;
	
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:   //退出系统
			wm.ExitSystem();
			break;
		case 1:   //增加员工
			wm.Add_Emp();
			break;
		case 2:   //显示员工
			wm.show_Emp();
			break;
		case 3:   //删除员工
			wm.Del_Emp();
			break;
		case 4:   //修改员工
			wm.Mod_Emp();
			break;
		case 5:   //查找员工
			wm.Find_Emp();
			break;
		case 6:   //排序员工
			wm.Sort_Emp();
			break;
		case 7:   //清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;

		}


	}
}