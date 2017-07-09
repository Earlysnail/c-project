#include"Commodity_manage.h"



void Commodity_manage::checkquantity(Commodity *com)
{
	com->checkquantity();
}
int Commodity_manage::findstate(Commodity *com)
{
	com->findstate();
	
		return 0;
	
}

int Commodity_manage::statechange(Commodity *com)
{	
	com->statechange();
	return 0;
}

int Commodity_manage::delitem(Commodity *com)
{
	com->delitem();

		return 0;
}

 
 
Commodity *Commodity_manage::query(char name[20])
{
	for (int i=0;i<=food_total;i++)
	{
		if ((strcmp(food_sum[i].get_com_name(),name)==0)&&(food_sum[i].get_com_flag()==0))
		{	
			return &food_sum[i];
		}
	}
		for (int i=0;i<=dress_total;i++)
	{
		if ((strcmp(dress_sum[i].get_com_name(),name)==0)&&(dress_sum[i].get_com_flag()==0))
		{	
			return &dress_sum[i];
		}
	}	for (int i=0;i<=appliance_total;i++)
	{
		if ((strcmp(appliance_sum[i].get_com_name(),name)==0)&&(appliance_sum[i].get_com_flag()==0))
		{	
			return &appliance_sum[i]
			;
		}
	}
	return NULL; 	 
}
Commodity *Commodity_manage::query(double num)
{
	for (int i=0;i<=food_total;i++)
	{
		if ((food_sum[i].get_com_num()==num)&&(food_sum[i].get_com_flag()==0))
		{	
			com=food_sum[i];
			return &food_sum[i];
		}
	}
	for (int i=0;i<=dress_total;i++)
	{
		if( (dress_sum[i].get_com_num()==num)&&(dress_sum[i].get_com_flag()==0))
		{	
			com=dress_sum[i];
			return &dress_sum[i];
		}
	}	
	for (int i=0;i<=appliance_total;i++)
	{
		if ((appliance_sum[i].get_com_num()==num)&&(appliance_sum[i].get_com_flag()==0))
		{	
			com=appliance_sum[i];
			return &appliance_sum[i];
		}
	}
	return NULL; 	 
}

Commodity_manage::Commodity_manage()
{
	food_total=-1;
	dress_total=-1;
	appliance_total=-1;
	food food_n; 
	fstream file("food.dat",ios::in);
	while(1)
	{
		file.read((char *)&food_n,sizeof(food_n));
		if (!file)break;
		if(food_n.get_com_flag()==0)
		{
			food_total++;
			food_sum[food_total]=food_n;
		}
		
	}
	file.close();
	
	dress dress_n; 
	file.open("dress.dat",ios::in);
	while(1)
	{
		file.read((char *)&dress_n,sizeof(dress_n));
		if (!file)break;
			if(dress_n.get_com_flag()==0)
		{
			dress_total++;
			dress_sum[dress_total]=dress_n;
		}

	}
	file.close();
	
	appliance appliance_n; 
	file.open("appliance.dat",ios::in);
	while(1)
	{
		file.read((char *)&appliance_n,sizeof(appliance_n));
		if (!file)break;
			if(appliance_n.get_com_flag()==0)
		{
			appliance_total++;
			appliance_sum[appliance_total]=appliance_n;;
		}

	}
	file.close();
	
}
Commodity_manage::~Commodity_manage()
{
	fstream file("appliance.dat",ios::out);
	for (int i=0;i<=appliance_total;i++)
	{
		if(appliance_sum[i].get_com_flag()==0)
		{
			file.write((char *)&appliance_sum[i],sizeof(appliance_sum[i]));
		}
	}
	file.close();
	
	file.open("food.dat",ios::out);
	for (int i=0;i<=food_total;i++)
	{
		if(food_sum[i].get_com_flag()==0)
		{
			file.write((char *)&food_sum[i],sizeof(food_sum[i]));
		}
	}
	file.close();
	
	file.open("dress.dat",ios::out);
	for (int i=0;i<=dress_total;i++)
	{
		if(dress_sum[i].get_com_flag()==0)
		{
			file.write((char *)&dress_sum[i],sizeof(dress_sum[i]));
		}
	}
	file.close();
}


int Commodity_manage::additem(food &food)
{
	food_total++;
	food_sum[food_total]=food;
	food_sum[food_total].additem();
	return 1;
}
int Commodity_manage::additem(dress &dress)
{
	dress_total++;
	dress_sum[dress_total]=dress;
	dress_sum[dress_total].additem();
	return 1;
}
int Commodity_manage::additem(appliance &app)
{
	appliance_total++;
	appliance_sum[appliance_total]=app;
	appliance_sum[appliance_total].additem();
	return 1;
}
	
void Commodity_manage::show()
{
  	for (int i=0;i<=food_total;i++)
  	{
	  if (food_sum[i].get_com_flag()==0)
	  {
		  food_sum[i].show_com();
	  }
	}
	for (int i=0;i<=dress_total;i++)
  	{
	  if (dress_sum[i].get_com_flag()==0)
	  {
		  dress_sum[i].show_com();
	  }
	}
	for (int i=0;i<=appliance_total;i++)
  	{
	  if (appliance_sum[i].get_com_flag()==0)
	  {
		  appliance_sum[i].show_com();
	  }
	}

}


void Commodity_manage::com_manage_menu()
{

    int choice=1;
    char name[20];
    int num;
    int dt=0;
    char s[10]="��";
    Commodity *p;
	while (choice!=0)
	{
     	cout << "\n" << "**************************************************************************" << endl;
        cout <<  "\n                                ��  Ʒ  ��  ��  " <<endl;
        cout <<  "\n                               1  ������Ʒ��Ϣ" << endl;
        cout <<  "\n                               2  ��Ʒ��Ϣ����" << endl;
	    cout <<  "\n                               3  ɾ����Ʒ��Ϣ" << endl;
    	cout <<  "\n                               4  ��Ʒ��Ϣ��ʾ" << endl;
        cout <<  "\n                               5  ������Ʒ��Ϣ" << endl;
        cout <<  "\n                               6  �����Ʒ������Ϣ" << endl;
        cout <<  "\n                               7  ��ѯ��Ʒ��� " << endl;
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
		case 1:
			
			cout<<"��������Ʒ����";cin>>name;
			cout<<"��������Ʒ��ţ�";cin>>num;
			cout<<"��������Ʒ���ʹ��루1ʳƷ 2��װ 3��������";int type_num;cin>>type_num;
			cout<<"��������Ʒ���ۣ�";double in;cin>>in;
			cout<<"��������Ʒ�ۼۣ�";double out;cin>>out;
			cout<<"�������¿�棺";int re;cin>>re;
			cout<<"���������ʱ�䣺";int year,mon,da;cout<<endl<<"�꣺";cin>>year;cout<<"�£�";cin>>mon;cout<<"�գ�";cin>>da; 
			if(type_num==1){cout<<"�����뱣���ڣ�";cin>>dt;food food1(2,name,num,type_num,year,mon,da,in,out,re,dt,s);additem(food1);}
			if(type_num==2){cout<<"�������װ���ڣ������ģ��������";cin>>s;dress dress1(2,name,num,type_num,year,mon,da,in,out,re,dt,s);additem(dress1);}
			if(type_num==3){appliance app(2,name,num,type_num,year,mon,da,in,out,re,dt,s);additem(app);}
			
			break;
	
		case 2:
			cout << "��������Ҫ�޸ĵ���Ʒ��:";
			cin>>name;
			if (NULL==(p=query(name)))
			{
				cout << "�Բ��𣬸���Ʒ������!  "<<endl;
				break;
			}
			else 
				statechange(p);
			
		 	break;
		case 3:
		   	cout <<"��������Ҫɾ������Ʒ��:"<<endl;
            cin>>name; 
			if (NULL==(p=query(name))) 
			{
				cout <<"�Բ��𣬸���Ʒ������!" << endl;
			    break;
			}
			else
				delitem(p);
			break;
		case 4:
			show();
			break;

		case 5:
			int selection;
			cout << "����Ʒ������->�밴1"<<endl;
			cout << "����Ʒ�������->�밴2"<<endl;
			cin >> selection;
			if(selection==1)
			{
				cout<<"��������Ʒ����";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"�Բ��𣬸���Ʒ������!"<< endl;
					break;
				}
				else
				 	p->show_com();
			}
			else if(selection==2)
			{
				cout<<"��������Ʒ��ţ�";
				cin>>num;
				if (NULL==(p=query(num)))
				{
					cout << "�Բ��𣬸���Ʒ������!" << endl;
					break;
				}
				else
						p->show_com();
			}
			else 
				cout << "�Բ���������������������!"<< endl;
			break;
			
		case 6:
				cout<<"��������Ʒ����";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"�Բ��𣬸���Ʒ������!"<< endl;
					break;
				}
				else
				 	checkquantity(p);
			break;
		case 7:
				cout<<"��������Ʒ����";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"�Բ��𣬸���Ʒ������!"<< endl;
					break;
				}
				else
				 	findstate(p);
			break;
		
		}
	}
}




