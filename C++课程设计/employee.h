#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"Date.h"
#define saleman_max 50
#define manager_max 3
#define warehouseman_max 3

class employee
{
	protected:
		int flag;//����ɾ����� 
		char emp_name[20];//ְ������ 
		long int emp_num;//ְ������ 
		int emp_desk_num;//������� 
		int emp_dept_num;//ְ����� 
		int month;//�·� 
		double salary;//����  
	public: 
		employee(int f=2,char name[20]={"0"},long int num=0,int desk_num=0,int dept_num=0,int m=0,double s=0){flag=f;strcpy(emp_name,name);emp_num=num;emp_desk_num=desk_num;emp_dept_num=dept_num;month=m;salary=s;}
		int operator=(employee &emp);
		void set_emp_name(){cin>>emp_name;};//���ĳ�Ա���� 
		void set_emp_num(){cin>>emp_num;};
		void set_emp_desk_num(){cin>>emp_desk_num;};
		void set_emp_dept_num(){cin>>emp_dept_num;};
		void set_month(){cin>>month;};
		void set_salary(){cin>>salary;};
		int get_emp_flag(){return(flag);};
		char* get_emp_name(){return(emp_name);};//��ȡ��Ա���� 
		double get_emp_num(){return(emp_num);};
		int get_emp_desk_num(){return(emp_desk_num);};
		int get_emp_dept_num(){return(emp_dept_num);};
		int get_month(){return(month);};
		double get_salary(){return(salary);};
		int addemployee(){flag=0;if(flag==0)return 1;return 0;}//���Ա����Ϣ 
		int delemployee(){flag=1;if(flag==1)return 1;return 0;};// ɾ��Ա����Ϣ 
		void show_emp(); //���Ա����Ϣ
		int statechange();//����Ա�����飬ְ����Ϣ 
		int findstate();//��ѯԱ��ְ����� 
		virtual double recordsalary()=0;//��¼Ա������ 
		
 }; 
 

#endif
