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
    char s[10]="无";
    Commodity *p;
	while (choice!=0)
	{
     	cout << "\n" << "**************************************************************************" << endl;
        cout <<  "\n                                商  品  管  理  " <<endl;
        cout <<  "\n                               1  新增商品信息" << endl;
        cout <<  "\n                               2  商品信息更改" << endl;
	    cout <<  "\n                               3  删除商品信息" << endl;
    	cout <<  "\n                               4  商品信息显示" << endl;
        cout <<  "\n                               5  搜索商品信息" << endl;
        cout <<  "\n                               6  检查商品质量信息" << endl;
        cout <<  "\n                               7  查询商品库存 " << endl;
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
		case 1:
			
			cout<<"请输入商品名：";cin>>name;
			cout<<"请输入商品编号：";cin>>num;
			cout<<"请输入商品类型代码（1食品 2服装 3电器）：";int type_num;cin>>type_num;
			cout<<"请输入商品进价：";double in;cin>>in;
			cout<<"请输入商品售价：";double out;cin>>out;
			cout<<"请输入月库存：";int re;cin>>re;
			cout<<"请输入进货时间：";int year,mon,da;cout<<endl<<"年：";cin>>year;cout<<"月：";cin>>mon;cout<<"日：";cin>>da; 
			if(type_num==1){cout<<"请输入保质期：";cin>>dt;food food1(2,name,num,type_num,year,mon,da,in,out,re,dt,s);additem(food1);}
			if(type_num==2){cout<<"请输入服装季节（春，夏，秋，冬）：";cin>>s;dress dress1(2,name,num,type_num,year,mon,da,in,out,re,dt,s);additem(dress1);}
			if(type_num==3){appliance app(2,name,num,type_num,year,mon,da,in,out,re,dt,s);additem(app);}
			
			break;
	
		case 2:
			cout << "请输入需要修改的商品名:";
			cin>>name;
			if (NULL==(p=query(name)))
			{
				cout << "对不起，该商品不存在!  "<<endl;
				break;
			}
			else 
				statechange(p);
			
		 	break;
		case 3:
		   	cout <<"请输入需要删除的商品名:"<<endl;
            cin>>name; 
			if (NULL==(p=query(name))) 
			{
				cout <<"对不起，该商品不存在!" << endl;
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
			cout << "按商品名搜索->请按1"<<endl;
			cout << "按商品编号搜索->请按2"<<endl;
			cin >> selection;
			if(selection==1)
			{
				cout<<"请输入商品名：";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"对不起，该商品不存在!"<< endl;
					break;
				}
				else
				 	p->show_com();
			}
			else if(selection==2)
			{
				cout<<"请输入商品编号：";
				cin>>num;
				if (NULL==(p=query(num)))
				{
					cout << "对不起，该商品不存在!" << endl;
					break;
				}
				else
						p->show_com();
			}
			else 
				cout << "对不起，输入有误，请重新输入!"<< endl;
			break;
			
		case 6:
				cout<<"请输入商品名：";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"对不起，该商品不存在!"<< endl;
					break;
				}
				else
				 	checkquantity(p);
			break;
		case 7:
				cout<<"请输入商品名：";
				cin>>name;
				if (NULL==(p=query(name)))
				{
					cout <<"对不起，该商品不存在!"<< endl;
					break;
				}
				else
				 	findstate(p);
			break;
		
		}
	}
}




