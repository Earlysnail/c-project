#include"saleman.h"


 int saleman::operator=(employee &emp)//��ֵ���ط�����   �����ۻ�Ա�����ֱ�Ӹ�ֵ
{
	flag=emp.get_emp_flag();
	strcpy(emp_name,emp.get_emp_name());
	emp_num=emp.get_emp_num();
	emp_desk_num=emp.get_emp_desk_num();
	emp_dept_num=emp.get_emp_dept_num();
	month=emp.get_month();
	salary=emp.get_salary();
}



double saleman::recordsalary()//�����ۻ�Ա������� 
{
	if(salary==2000)
	{
		cout<<emp_name<<month<<"�����۶�Ϊ��";cin>>salary;
		salary=2000+salary*5/100;
	}
	return(salary);
}

	
	
