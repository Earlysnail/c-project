#include"dress.h"
 int dress::operator=(Commodity &com)
{
	flag=com.get_com_flag();
	strcpy(com_name,com.get_com_name());
	com_num=com.get_com_num();
	com_type_num=com.get_com_type_num();
	com_in_price=com.get_com_in_price();
	com_out_price=com.get_com_out_price();
	repretroy=com.get_repretroy();
	com_begin_time.year=com.get_com_begin_time().year;
	com_begin_time.month=com.get_com_begin_time().month;
	com_begin_time.day=com.get_com_begin_time().day;
	com_deadline_time=com.get_com_deadline_time();
	strcpy(com_season,com.get_com_season());
}

void dress::checkquantity()
{
	char season[20];
	cout<<"���������ڼ��ڣ������ģ��������";cin>>season;
	if(strcmp(com_season,season)==0)
	{
		cout<<"��װδ��ʱ��"<<endl;
	 }
	else
		cout<<"��װ�ѹ�ʱ���������ۣ�"<<endl; 
}
 
