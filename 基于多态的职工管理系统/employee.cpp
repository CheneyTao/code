#include"employee.h"
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Employee::showInfo()
{
	cout <<"id��\t"<< m_Id 
	 << "\tName:" << m_Name 
	 << "\tDeptId:" << m_DeptId
	<< "\tְ��:��ɾ����ɷ�������   "  <<endl;
}

string Employee::getDeptName()
{
	return string("\tԱ��");
}
