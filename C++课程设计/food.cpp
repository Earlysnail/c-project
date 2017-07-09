#include"food.h"
int food::operator=(Commodity &com)
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



void food::checkquantity()
{
	int now_year,now_month,now_day,time;
	cout<<"请输入现在日期：";cin>>now_year;cin>>now_month;cin>>now_day;
	time=(now_year-com_begin_time.year-1)*365+(12+now_month-1-com_begin_time.month)*30+(30+now_day-com_begin_time.day);
	if(time>com_deadline_time*30)
	{
		cout<<"食品过期！"<<endl; 
	 }
	else
		cout<<"食品未过期！"<<endl; 

}

