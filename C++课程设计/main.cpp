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
		cout<<"\n                                �̳����۹���ϵͳ"<<endl; 
		cout<<"\n                                   1 ���¹���"<<endl; 
		cout<<"\n                                   2 ��Ʒ����"<<endl;
		cout<<"\n                                   3 �˳�ϵͳ"<<endl;
		cout << "\n" << "**************************************************************************" << endl;
        cout <<"          ����������е�����:";
        do
		{
			cin >> choice;
			if(choice<0||choice>4)
				cout << "�����������������!" << endl;
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




