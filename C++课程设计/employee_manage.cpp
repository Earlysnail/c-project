
#include"employee_manage.h"

void employee_manage::recordsalary(employee *emp)//��ʾԱ�����¹��� 
{
	cout<<"Ա�����ʣ�"<<emp->recordsalary()<<endl;

}
int employee_manage::findstate(employee *emp)//��ѯԱ��ְ�����
{
	emp->findstate();	return 0;
	
}

int employee_manage::statechange(employee *emp)//����Ա�����鼰ְ����� 
{
	emp->statechange();return 0;
}
int employee_manage::delemployee(employee *emp)//ɾ��Ա����Ϣ 
{
	emp->delemployee();return 1;
	return 0;
}

 
employee *employee_manage::query(char name[20])//����������Ա����Ϣ 
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
employee *employee_manage::query(double num)//���������Ա����Ϣ
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
employee *employee_manage::query(int month)//���·ݲ���Ա����Ϣ
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
	 



employee_manage::employee_manage()//���ļ��ж�ȡ����Ա����Ϣ 
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
employee_manage::~employee_manage()//��Ա����Ϣд���ļ� 
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


int employee_manage::addemployee(saleman &sale)//����ۻ�Ա��Ϣ 
{
	saleman_total++;
	saleman_sum[saleman_total]=sale;
	saleman_sum[saleman_total].addemployee();
	return 1;
}
int employee_manage::addemployee(manager &mana)//��Ӿ�����Ϣ 
{
	manager_total++;
	manager_sum[manager_total]=mana;
	manager_sum[manager_total].addemployee();
	return 1;
}
int employee_manage::addemployee(warehouseman &ware)//��ӿ����Ϣ 
{
	warehouseman_total++;
	warehouseman_sum[warehouseman_total]=ware;
	warehouseman_sum[warehouseman_total].addemployee();
	return 1;
}
	
void employee_manage::show()//��ʾȫ��Ա����Ϣ 
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


void employee_manage::emp_manage_menu()//���¹���ϵͳ�ܲ˵� 
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
        cout <<  "\n                                ��  ��  ��  ��  " <<endl;
        cout <<  "\n                               1  ����Ա����Ϣ" << endl;
        cout <<  "\n                               2  Ա����Ϣ����" << endl;
	    cout <<  "\n                               3  ɾ��Ա����Ϣ" << endl;
    	cout <<  "\n                               4  Ա����Ϣ��ʾ" << endl;
        cout <<  "\n                               5  ����Ա����Ϣ" << endl;
        cout <<  "\n                               6  ��¼Ա������" << endl;
        cout <<  "\n                               7  ��ѯԱ��ְ����� " << endl;
       	cout <<  "\n                               0  ��ȫ�˳�ģ��" << endl;
       	
    	cout << "\n" << "**************************************************************************" << endl;
	    cout <<"          ����������е�����:";
		do
		{
			cin >> choice;
			if(choice<0||choice>7)
				cout << "�Բ��������������֤��������!" << endl;
			else 
				break;
		}while(1);
		switch (choice)
		{
		case 1: // ����Ա����Ϣ
			cout<<"������Ա��������";cin>>name;
			cout<<"������Ա����ţ�";cin>>num;
			cout<<"������Ա����̨���루1ʳƷ��2��װ��3��������";int desk_num;cin>>desk_num;
			cout<<"������Ա��ְ����루1�ۻ�Ա��2����3��ܣ���";int dept_num;cin>>dept_num; 
			cout<<"�������·ݣ�";cin>>m;
			if(dept_num==1){saleman sale(0,name,num,desk_num,dept_num,m,s);addemployee(sale);}
			if(dept_num==2){manager mana(0,name,num,desk_num,dept_num,m,s);addemployee(mana);}
			if(dept_num==3){warehouseman ware(0,name,num,desk_num,dept_num,m,s);addemployee(ware);}
			break;
		
	case 2:// Ա����Ϣ����
			cout << "��������Ҫ�޸ĵ�Ա��������:";
			cin>>name;
			if (NULL==(p=query(name)))
			{
				cout << "�Բ��𣬸�Ա��������!  "<<endl;
				break;
			}
			else 
				statechange(p);
			
		 	break;
		case 3://ɾ��Ա����Ϣ 
		   	cout <<"��������Ҫɾ����Ա��������:"<<endl;
            cin>>name; 
			if (NULL==(p=query(name)))
			{
				cout <<"�Բ��𣬸�Ա��������!" << endl;
			    break;
			}
			else
			delemployee(p);
			break;
		case 4:// Ա����Ϣ��ʾ
			show();
			break;

		case 5://����Ա����Ϣ 
			int selection;
			cout << "��Ա����������->�밴1"<<endl;
			cout << "��Ա���������->�밴2"<<endl;
			cout << "���·�����->�밴3"<<endl;
			cin >> selection;
			if(selection==1)//���������� 
			{
				cout<<"������Ա��������";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"�Բ��𣬸�Ա��������!"<< endl;
					break;
				}
				else
					p->show_emp();
			}
			else if(selection==2)//����Ų��� 
			{
				cout<<"������Ա����ţ�";
				cin>>num;
				if (NULL==(p=query(num)))
				{
					cout << "�Բ��𣬸�Ա��������!" << endl;
					break;
				}
				else
				p->show_emp();
			}
		     else if(selection==3)//���·ݲ���
			{
				cout<<"�������·ݣ�";
				cin>>m;
				if (NULL!=(p=query(m)))
				{
					cout << "�Բ���Ա��������!" << endl;
					break;
				}
			}
			else 
				cout << "�Բ���������������������!"<< endl;
			break;
				
		case 6://��¼Ա������ 
				cout<<"������Ա��������";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"�Բ��𣬸�Ա��������!"<< endl;
					break;
				}
				else
					recordsalary(p);
			break;
		case 7://��ѯԱ��ְ����� 
				cout<<"������Ա��������";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"�Բ��𣬸�Ա��������!"<< endl;
					break;
				}
				else
				 	findstate(p);
			break;
		
		}
	}
}



