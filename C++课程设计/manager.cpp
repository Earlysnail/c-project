#include"manager.h"
int manager::operator=(employee &emp)//��ֵ���ط�����   ���ھ�������ֱ�Ӹ�ֵ 
{
	flag=emp.get_emp_flag();
	strcpy(emp_name,emp.get_emp_name());
	emp_num=emp.get_emp_num();
	emp_desk_num=emp.get_emp_desk_num();
	emp_dept_num=emp.get_emp_dept_num();
	month=emp.get_month();
	salary=emp.get_salary();
}

double manager::recordsalary()//��¼����������� 
{
	if(salary==4000)
	{
		cout<<emp_name<<month<<"��̨��Ӫҵ��Ϊ��";cin>>salary;
		salary=4000+salary*5/100;
	}
	return(salary);
}

