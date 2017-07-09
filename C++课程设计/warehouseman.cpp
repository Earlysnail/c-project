#include"warehouseman.h"
int warehouseman::operator=(employee &emp)//赋值运载符重载   用于库管对象间直接赋值 
{
	flag=emp.get_emp_flag();
	strcpy(emp_name,emp.get_emp_name());
	emp_num=emp.get_emp_num();
	emp_desk_num=emp.get_emp_desk_num();
	emp_dept_num=emp.get_emp_dept_num();
	month=emp.get_month();
	salary=emp.get_salary();

}


double warehouseman::recordsalary()//记录库管类对象工资 
{
	if(salary==3000)
	{
		cout<<emp_name<<month<<"奖金为：";cin>>salary;
		salary=4000+salary;
	}
	return(salary);
}





