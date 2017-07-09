#include"manager.h"
int manager::operator=(employee &emp)//赋值运载符重载   用于经理对象间直接赋值 
{
	flag=emp.get_emp_flag();
	strcpy(emp_name,emp.get_emp_name());
	emp_num=emp.get_emp_num();
	emp_desk_num=emp.get_emp_desk_num();
	emp_dept_num=emp.get_emp_dept_num();
	month=emp.get_month();
	salary=emp.get_salary();
}

double manager::recordsalary()//记录经理类对象工资 
{
	if(salary==4000)
	{
		cout<<emp_name<<month<<"柜台总营业额为：";cin>>salary;
		salary=4000+salary*5/100;
	}
	return(salary);
}

