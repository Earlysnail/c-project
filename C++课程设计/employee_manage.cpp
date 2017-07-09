
#include"employee_manage.h"

void employee_manage::recordsalary(employee *emp)//显示员工本月工资 
{
	cout<<"员工工资："<<emp->recordsalary()<<endl;

}
int employee_manage::findstate(employee *emp)//查询员工职务代码
{
	emp->findstate();	return 0;
	
}

int employee_manage::statechange(employee *emp)//更改员工柜组及职务代码 
{
	emp->statechange();return 0;
}
int employee_manage::delemployee(employee *emp)//删除员工信息 
{
	emp->delemployee();return 1;
	return 0;
}

 
employee *employee_manage::query(char name[20])//按姓名查找员工信息 
{
	for (int i=0;i<=saleman_total;i++)
	{
		if ((strcmp(saleman_sum[i].get_emp_name(),name)==0)&&(saleman_sum[i].get_emp_flag()==0))
		{	
			return &saleman_sum[i];
		}
	}
		for (int i=0;i<=manager_total;i++)
	{
		if ((strcmp(manager_sum[i].get_emp_name(),name)==0)&&(manager_sum[i].get_emp_flag()==0))
		{	
			return &manager_sum[i];
		}
	}	for (int i=0;i<=warehouseman_total;i++)
	{
		if ((strcmp(warehouseman_sum[i].get_emp_name(),name)==0)&&(warehouseman_sum[i].get_emp_flag()==0))
		{	
			return &warehouseman_sum[i];
		}
	}
	return NULL; 	 
}
employee *employee_manage::query(double num)//按编码查找员工信息
{
	for (int i=0;i<=saleman_total;i++)
	{
		if ((saleman_sum[i].get_emp_num()==num)&&(saleman_sum[i].get_emp_flag()==0))
		{	
			return &saleman_sum[i];
		}
	}
	for (int i=0;i<=manager_total;i++)
	{
		if( (manager_sum[i].get_emp_num()==num)&&(manager_sum[i].get_emp_flag()==0))
		{	
			return &manager_sum[i];
		}
	}	
	for (int i=0;i<=warehouseman_total;i++)
	{
		if ((warehouseman_sum[i].get_emp_num()==num)&&(warehouseman_sum[i].get_emp_flag()==0))
		{	
			return &warehouseman_sum[i];
		}
	}
	return NULL; 	 
}
employee *employee_manage::query(int month)//按月份查找员工信息
{
	for (int i=0;i<=saleman_total;i++)
	{
		if ((saleman_sum[i].get_month()==month)&&(saleman_sum[i].get_emp_flag()==0))
		{	
			saleman_sum[i].show_emp();
		}
	}
	for (int i=0;i<=manager_total;i++)
	{
		if ((manager_sum[i].get_month()==month)&&(manager_sum[i].get_emp_flag()==0))
		{	
			manager_sum[i].show_emp();
		}
	}	
	for (int i=0;i<=warehouseman_total;i++)
	{
		if ((warehouseman_sum[i].get_month()==month)&&(warehouseman_sum[i].get_emp_flag()==0))
		{	
			warehouseman_sum[i].show_emp();
		}
	}
	return NULL; 	 
}
	 



employee_manage::employee_manage()//从文件中读取各类员工信息 
{
	saleman_total=-1;
	manager_total=-1;
	warehouseman_total=-1;
	saleman saleman_n; 
	fstream file("saleman.dat",ios::in);
	while(1)
	{
		file.read((char *)&saleman_n,sizeof(saleman_n));
		if (!file)break;
		if(saleman_n.get_emp_flag()==0)
		{
			saleman_total++;
			saleman_sum[saleman_total]=saleman_n;
		}
		
	}
	file.close();
	
	manager manager_n; 
	file.open("manager.dat",ios::in);
	while(1)
	{
		file.read((char *)&manager_n,sizeof(manager_n));
		if (!file)break;
			if(manager_n.get_emp_flag()==0)
		{
			manager_total++;
			manager_sum[manager_total]=manager_n;
		}

	}
	file.close();
	
	warehouseman warehouseman_n; 
	file.open("warehouseman.dat",ios::in);
	while(1)
	{
		file.read((char *)&warehouseman_n,sizeof(warehouseman_n));
		if (!file)break;
			if(warehouseman_n.get_emp_flag()==0)
		{
			warehouseman_total++;
			warehouseman_sum[warehouseman_total]=warehouseman_n;;
		}

	}
	file.close();
	
}
employee_manage::~employee_manage()//将员工信息写入文件 
{
	fstream file("warehouseman.dat",ios::out);
	for (int i=0;i<=warehouseman_total;i++)
	{
		if(warehouseman_sum[i].get_emp_flag()==0)
		{
			file.write((char *)&warehouseman_sum[i],sizeof(warehouseman_sum[i]));
		}
	}
	file.close();
	
	file.open("saleman.dat",ios::out);
	for (int i=0;i<=saleman_total;i++)
	{
		if(saleman_sum[i].get_emp_flag()==0)
		{
			file.write((char *)&saleman_sum[i],sizeof(saleman_sum[i]));
		}
	}
	file.close();
	
	file.open("manager.dat",ios::out);
	for (int i=0;i<=manager_total;i++)
	{
		if(manager_sum[i].get_emp_flag()==0)
		{
			file.write((char *)&manager_sum[i],sizeof(manager_sum[i]));
		}
	}
	file.close();
}


int employee_manage::addemployee(saleman &sale)//添加售货员信息 
{
	saleman_total++;
	saleman_sum[saleman_total]=sale;
	saleman_sum[saleman_total].addemployee();
	return 1;
}
int employee_manage::addemployee(manager &mana)//添加经理信息 
{
	manager_total++;
	manager_sum[manager_total]=mana;
	manager_sum[manager_total].addemployee();
	return 1;
}
int employee_manage::addemployee(warehouseman &ware)//添加库管信息 
{
	warehouseman_total++;
	warehouseman_sum[warehouseman_total]=ware;
	warehouseman_sum[warehouseman_total].addemployee();
	return 1;
}
	
void employee_manage::show()//显示全体员工信息 
{
  	for (int i=0;i<=saleman_total;i++)
  	{
	  if (saleman_sum[i].get_emp_flag()==0)
	  {
		  saleman_sum[i].show_emp();
	  }
	}
	for (int i=0;i<=manager_total;i++)
  	{
	  if (manager_sum[i].get_emp_flag()==0)
	  {
		  manager_sum[i].show_emp();
	  }
	}
	for (int i=0;i<=warehouseman_total;i++)
  	{
	  if (warehouseman_sum[i].get_emp_flag()==0)
	  {
		  warehouseman_sum[i].show_emp();
	  }
	}

}


void employee_manage::emp_manage_menu()//人事管理系统总菜单 
{

    int choice=1;
    char name[20]; 
    double num;
    int m,s=0;
    manager mana;
    warehouseman ware;
    employee *p;
	while (choice!=0)
	{
     	cout << "\n" << "**************************************************************************" << endl;
        cout <<  "\n                                人  事  管  理  " <<endl;
        cout <<  "\n                               1  新增员工信息" << endl;
        cout <<  "\n                               2  员工信息更改" << endl;
	    cout <<  "\n                               3  删除员工信息" << endl;
    	cout <<  "\n                               4  员工信息显示" << endl;
        cout <<  "\n                               5  搜索员工信息" << endl;
        cout <<  "\n                               6  记录员工工资" << endl;
        cout <<  "\n                               7  查询员工职务代码 " << endl;
       	cout <<  "\n                               0  安全退出模块" << endl;
       	
    	cout << "\n" << "**************************************************************************" << endl;
	    cout <<"          请输入相对有的数字:";
		do
		{
			cin >> choice;
			if(choice<0||choice>7)
				cout << "对不起，输入有误，请查证后再输入!" << endl;
			else 
				break;
		}while(1);
		switch (choice)
		{
		case 1: // 新增员工信息
			cout<<"请输入员工姓名：";cin>>name;
			cout<<"请输入员工编号：";cin>>num;
			cout<<"请输入员工柜台代码（1食品，2服装，3电器）：";int desk_num;cin>>desk_num;
			cout<<"请输入员工职务代码（1售货员，2经理，3库管）：";int dept_num;cin>>dept_num; 
			cout<<"请输入月份：";cin>>m;
			if(dept_num==1){saleman sale(0,name,num,desk_num,dept_num,m,s);addemployee(sale);}
			if(dept_num==2){manager mana(0,name,num,desk_num,dept_num,m,s);addemployee(mana);}
			if(dept_num==3){warehouseman ware(0,name,num,desk_num,dept_num,m,s);addemployee(ware);}
			break;
		
	case 2:// 员工信息更改
			cout << "请输入需要修改的员工的姓名:";
			cin>>name;
			if (NULL==(p=query(name)))
			{
				cout << "对不起，该员工不存在!  "<<endl;
				break;
			}
			else 
				statechange(p);
			
		 	break;
		case 3://删除员工信息 
		   	cout <<"请输入需要删除的员工的姓名:"<<endl;
            cin>>name; 
			if (NULL==(p=query(name)))
			{
				cout <<"对不起，该员工不存在!" << endl;
			    break;
			}
			else
			delemployee(p);
			break;
		case 4:// 员工信息显示
			show();
			break;

		case 5://搜索员工信息 
			int selection;
			cout << "按员工姓名搜索->请按1"<<endl;
			cout << "按员工编号搜索->请按2"<<endl;
			cout << "按月份搜索->请按3"<<endl;
			cin >> selection;
			if(selection==1)//按姓名查找 
			{
				cout<<"请输入员工姓名：";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"对不起，该员工不存在!"<< endl;
					break;
				}
				else
					p->show_emp();
			}
			else if(selection==2)//按编号查找 
			{
				cout<<"请输入员工编号：";
				cin>>num;
				if (NULL==(p=query(num)))
				{
					cout << "对不起，该员工不存在!" << endl;
					break;
				}
				else
				p->show_emp();
			}
		     else if(selection==3)//按月份查找
			{
				cout<<"请输入月份：";
				cin>>m;
				if (NULL!=(p=query(m)))
				{
					cout << "对不起，员工不存在!" << endl;
					break;
				}
			}
			else 
				cout << "对不起，输入有误，请重新输入!"<< endl;
			break;
				
		case 6://记录员工工资 
				cout<<"请输入员工姓名：";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"对不起，该员工不存在!"<< endl;
					break;
				}
				else
					recordsalary(p);
			break;
		case 7://查询员工职务代码 
				cout<<"请输入员工姓名：";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"对不起，该员工不存在!"<< endl;
					break;
				}
				else
				 	findstate(p);
			break;
		
		}
	}
}



