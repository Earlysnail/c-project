
#include"employee.h"

int employee::operator=(employee &emp)//��ֵ���ط�����   ����Ա�������ֱ�Ӹ�ֵ 
{
	flag=emp.get_emp_flag();
	strcpy(emp_name,emp.get_emp_name());
	emp_num=emp.get_emp_num();
	emp_desk_num=emp.get_emp_desk_num();
	emp_dept_num=emp.get_emp_dept_num();
	month=emp.get_month();
	salary=emp.get_salary();
}


void employee::show_emp()             //���Ա����Ϣ
{
	cout <<"Ա��������"<<emp_name<<endl<<"Ա����ţ�"<<emp_num<<endl;
	if(emp_desk_num==1)cout<<"����:"<<"ʳƷ"<<endl;
	if(emp_desk_num==2)cout<<"����:"<<"��װ"<<endl;
	if(emp_desk_num==3)cout<<"����:"<<"����"<<endl;
	if(emp_dept_num==1)cout<<"ְ��:"<<"�ۻ�Ա"<<endl;
	if(emp_dept_num==2)cout<<"ְ��:"<<"����"<<endl;
	if(emp_dept_num==3)cout<<"ְ��:"<<"���"<<endl;
	cout<<"�·�:"<<month<<"��"<<endl<<"���ʣ�"<<salary<<endl<<endl;
}
int employee::statechange()//����Ա��������룬ְ�������Ϣ
{
	cout<<"������Ա����̨���룺";set_emp_desk_num();
	cout<<"������Ա��ְ����룺";set_emp_dept_num();
	return 1;
}
int employee::findstate()//��ѯԱ��ְ�������Ϣ
{
	if(get_emp_dept_num()>0&&get_emp_dept_num()<4)
	{
		cout<<"Ա��ְ����룺"<<get_emp_dept_num();
		if(get_emp_dept_num()==1)cout<<"(�ۻ�Ա)"<<endl;return 1;
		if(get_emp_dept_num()==2)cout<<"(����)"<<endl;return 1;
		if(get_emp_dept_num()==3)cout<<"(���)"<<endl;return 1;
	}
	return 0;
	
}

 

 
