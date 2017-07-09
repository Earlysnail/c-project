#include"saleman.h"


 int saleman::operator=(employee &emp)//赋值运载符重载   用于售货员对象间直接赋值
{
	flag=emp.get_emp_flag();
	strcpy(emp_name,emp.get_emp_name());
	emp_num=emp.get_emp_num();
	emp_desk_num=emp.get_emp_desk_num();
	emp_dept_num=emp.get_emp_dept_num();
	month=emp.get_month();
	salary=emp.get_salary();
}



double saleman::recordsalary()//计算售货员类对象工资 
{
	if(salary==2000)
	{
		cout<<emp_name<<month<<"月销售额为：";cin>>salary;
		salary=2000+salary*5/100;
	}
	return(salary);
}

	
	
