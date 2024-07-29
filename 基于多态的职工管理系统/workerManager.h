#pragma once
#include <iostream>
#include "workerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;
class WorkerManager
{
public:
	WorkerManager();
	void Show_Menu();
	void ExitSystem();
	//记录职工人数
	int m_EmpNum=0;

	//保存员工
	void save();


	//职工数组指针
	Worker** m_EmpArray;

	//增加员工
	void Add_Emp(); 
	//判断文件是否为空
	bool m_FileIsEmpty;
	
	//统计文件中人数
	 int get_EmpNum();
	//void show();
	 
	//初始化员工
	 void init_Emp();

	 //显示员工
	 void show_Emp();

	 //查找员工
	 int IsExist(int id);

	 //删除员工
	 void Del_Emp();

	 //修改员工信息
	 void Mod_Emp();

	 //查找员工
	 void Find_Emp();

	 //按编号排序
	 void Sort_Emp();

	 //清空文件
	 void Clean_File();
    ~WorkerManager();

};
