#ifndef SALEMAN_H
#define SALEMAN_H
#include"employee.h"

class saleman:public employee//售货员派生类 
{	
	public:
		saleman(){}
		saleman(int f,char name[20],double num,int desk_num,int dept_num,int m,double s):employee(f,name,num,desk_num,dept_num,m,s){salary=2000;}
		int operator=(employee &emp);
		virtual double recordsalary();
};

#endif
