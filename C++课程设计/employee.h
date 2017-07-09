#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"Date.h"
#define saleman_max 50
#define manager_max 3
#define warehouseman_max 3

class employee
{
	protected:
		int flag;//设置删除标记 
		char emp_name[20];//职工姓名 
		long int emp_num;//职工编码 
		int emp_desk_num;//柜组代码 
		int emp_dept_num;//职务代码 
		int month;//月份 
		double salary;//工资  
	public: 
		employee(int f=2,char name[20]={"0"},long int num=0,int desk_num=0,int dept_num=0,int m=0,double s=0){flag=f;strcpy(emp_name,name);emp_num=num;emp_desk_num=desk_num;emp_dept_num=dept_num;month=m;salary=s;}
		int operator=(employee &emp);
		void set_emp_name(){cin>>emp_name;};//更改成员数据 
		void set_emp_num(){cin>>emp_num;};
		void set_emp_desk_num(){cin>>emp_desk_num;};
		void set_emp_dept_num(){cin>>emp_dept_num;};
		void set_month(){cin>>month;};
		void set_salary(){cin>>salary;};
		int get_emp_flag(){return(flag);};
		char* get_emp_name(){return(emp_name);};//获取成员数据 
		double get_emp_num(){return(emp_num);};
		int get_emp_desk_num(){return(emp_desk_num);};
		int get_emp_dept_num(){return(emp_dept_num);};
		int get_month(){return(month);};
		double get_salary(){return(salary);};
		int addemployee(){flag=0;if(flag==0)return 1;return 0;}//添加员工信息 
		int delemployee(){flag=1;if(flag==1)return 1;return 0;};// 删除员工信息 
		void show_emp(); //输出员工信息
		int statechange();//更改员工柜组，职务信息 
		int findstate();//查询员工职务代码 
		virtual double recordsalary()=0;//记录员工工资 
		
 }; 
 

#endif
