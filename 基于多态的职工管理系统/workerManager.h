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
	//��¼ְ������
	int m_EmpNum=0;

	//����Ա��
	void save();


	//ְ������ָ��
	Worker** m_EmpArray;

	//����Ա��
	void Add_Emp(); 
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	
	//ͳ���ļ�������
	 int get_EmpNum();
	//void show();
	 
	//��ʼ��Ա��
	 void init_Emp();

	 //��ʾԱ��
	 void show_Emp();

	 //����Ա��
	 int IsExist(int id);

	 //ɾ��Ա��
	 void Del_Emp();

	 //�޸�Ա����Ϣ
	 void Mod_Emp();

	 //����Ա��
	 void Find_Emp();

	 //���������
	 void Sort_Emp();

	 //����ļ�
	 void Clean_File();
    ~WorkerManager();

};
