#include"warehouseman.h"
int warehouseman::operator=(employee &emp)//��ֵ���ط�����   ���ڿ�ܶ����ֱ�Ӹ�ֵ 
{
	flag=emp.get_emp_flag();
	strcpy(emp_name,emp.get_emp_name());
	emp_num=emp.get_emp_num();
	emp_desk_num=emp.get_emp_desk_num();
	emp_dept_num=emp.get_emp_dept_num();
	month=emp.get_month();
	salary=emp.get_salary();

}


double warehouseman::recordsalary()//��¼���������� 
{
	if(salary==3000)
	{
		cout<<emp_name<<month<<"����Ϊ��";cin>>salary;
		salary=4000+salary;
	}
	return(salary);
}





