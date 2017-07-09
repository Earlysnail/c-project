#ifndef WAREHOUSEMAN_H
#define WAREHOUSEMAN_H
#include"employee.h"
class  warehouseman:public employee//ø‚π‹≈……˙¿‡ 
{
	public:
	warehouseman(){}
	warehouseman(int f,char name[20],double num,int desk_num,int dept_num,int m,double s):employee(f,name,num,desk_num,dept_num,m,s){salary=3000;}
	int operator=(employee &emp);
	virtual double recordsalary();
	
}; 

#endif
