#include"manager.h"
Manager::Manager(int id, string name, int dId)
{
	this->m_Name = name;
	this->m_Id = id;
	this->m_DeptId = dId;
}
void Manager::showInfo()
{
	cout << "id：\t" << m_Id 
	 << "\tName:" << m_Name 
	 << "\tDeptId:" << m_DeptId
	<< "\t职责:完成老板任务，安排员工任务   "<<endl;
}
string Manager::getDeptName()
{
	return string("\t 经理");
}