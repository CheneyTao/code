#pragma once
#include<iostream>

#include "worker.h"
using namespace std;
class Employee :public Worker
{
public:
	Employee(int id, string name, int dId);
	virtual void showInfo() ;
	virtual string getDeptName() ;
	//int m_Id;
	//string m_Name;
	//int m_DeptId;
};
