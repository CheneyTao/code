#include"boss.h"
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Boss::showInfo()
{
	cout << "id：\t" << m_Id
	 << "\tName:" << m_Name 
	 << "\tDeptId:" << m_DeptId
	 << "\t职责:管理经理，安排经理工作   " <<endl;
}

string Boss::getDeptName()
{
	return string("员工");
}
