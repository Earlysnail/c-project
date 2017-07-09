
#include"employee.h"

int employee::operator=(employee &emp)//赋值运载符重载   用于员工对象间直接赋值 
{
	flag=emp.get_emp_flag();
	strcpy(emp_name,emp.get_emp_name());
	emp_num=emp.get_emp_num();
	emp_desk_num=emp.get_emp_desk_num();
	emp_dept_num=emp.get_emp_dept_num();
	month=emp.get_month();
	salary=emp.get_salary();
}


void employee::show_emp()             //输出员工信息
{
	cout <<"员工姓名："<<emp_name<<endl<<"员工编号："<<emp_num<<endl;
	if(emp_desk_num==1)cout<<"柜组:"<<"食品"<<endl;
	if(emp_desk_num==2)cout<<"柜组:"<<"服装"<<endl;
	if(emp_desk_num==3)cout<<"柜组:"<<"电器"<<endl;
	if(emp_dept_num==1)cout<<"职务:"<<"售货员"<<endl;
	if(emp_dept_num==2)cout<<"职务:"<<"经理"<<endl;
	if(emp_dept_num==3)cout<<"职务:"<<"库管"<<endl;
	cout<<"月份:"<<month<<"月"<<endl<<"工资："<<salary<<endl<<endl;
}
int employee::statechange()//更改员工柜组代码，职务代码信息
{
	cout<<"请输入员工柜台代码：";set_emp_desk_num();
	cout<<"请输入员工职务代码：";set_emp_dept_num();
	return 1;
}
int employee::findstate()//查询员工职务代码信息
{
	if(get_emp_dept_num()>0&&get_emp_dept_num()<4)
	{
		cout<<"员工职务代码："<<get_emp_dept_num();
		if(get_emp_dept_num()==1)cout<<"(售货员)"<<endl;return 1;
		if(get_emp_dept_num()==2)cout<<"(经理)"<<endl;return 1;
		if(get_emp_dept_num()==3)cout<<"(库管)"<<endl;return 1;
	}
	return 0;
	
}

 

 
