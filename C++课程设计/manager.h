#ifndef MANAGER_H
#define MANAGER_H
#include"employee.h"
class  manager:public employee//经理派生类
{
	public:
	manager(){}
	manager(int f,char name[20],double num,int desk_num,int dept_num,int m,double s):employee(f,name,num,desk_num,dept_num,m,s){salary=4000;}
	int operator=(employee &emp);
	virtual double recordsalary();
};


#endif
