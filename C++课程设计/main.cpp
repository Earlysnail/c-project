#include"employee_manage.h"
#include"Commodity_manage.h"
int main()
{    
	int choice=1;
	employee_manage emp_manage_data;
	Commodity_manage com_manage_data;
	while(choice!=3)
	{       
		cout << "\n" << "**************************************************************************" << endl;
		cout<<"\n                                商场销售管理系统"<<endl; 
		cout<<"\n                                   1 人事管理"<<endl; 
		cout<<"\n                                   2 商品管理"<<endl;
		cout<<"\n                                   3 退出系统"<<endl;
		cout << "\n" << "**************************************************************************" << endl;
        cout <<"          请输入相对有的数字:";
        do
		{
			cin >> choice;
			if(choice<0||choice>4)
				cout << "输入错误，请重新输入!" << endl;
			else 
				break;
		}while(1);
		switch (choice)
		{
		case 1:
			emp_manage_data.emp_manage_menu(); 
			break;
		case 2:
			com_manage_data.com_manage_menu();
			break;
		case 3:
			break; 
		}

	
	}
	return 0;
}




