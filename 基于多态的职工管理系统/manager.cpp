#include"manager.h"
Manager::Manager(int id, string name, int dId)
{
	this->m_Name = name;
	this->m_Id = id;
	this->m_DeptId = dId;
}
void Manager::showInfo()
{
	cout << "id��\t" << m_Id 
	 << "\tName:" << m_Name 
	 << "\tDeptId:" << m_DeptId
	<< "\tְ��:����ϰ����񣬰���Ա������   "<<endl;
}
string Manager::getDeptName()
{
	return string("\t ����");
}