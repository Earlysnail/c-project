
#include"Commodity.h"
int Commodity::operator=(Commodity &com)//赋值运载符重载   用于商品对象间直接赋值
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


void Commodity::show_com()             //输出商品信息
	{
	cout <<"商品名："<<com_name<<endl<<"商品编码："<<com_num<<endl;
	if(com_type_num==1)cout<<"商品类型："<<"食品"<<endl; 
	if(com_type_num==2)cout<<"商品类型："<<"服装"<<endl; 
	if(com_type_num==3)cout<<"商品类型："<<"电器"<<endl; 
	cout<<"进价 :"<<com_in_price<<endl<<"售价："<<com_out_price<<endl<<"库存: "<<repretroy<<endl<<"进货时间 :"<<endl;com_begin_time.show();
	if(com_type_num==1)cout<<"食品保质期 :"<<com_deadline_time<<"月"<<endl;
	if(com_type_num==2)cout<<"服装季节："<<com_season<<"季"<<endl;
	cout<<endl;
	}

	
void Commodity::checkquantity()
{
	
} 
int Commodity::findstate()//检查库存  
{
	cout<<"商品库存："<<get_repretroy()<<endl;
	if(get_repretroy()<10)
	{
		cout<<"库存不足！"<<endl; 
	}
} 
int Commodity::statechange()//更改商品进价和售价
{
	cout<<"请输入商品进价：";set_com_in_price();
	cout<<"请输入商品售价：";set_com_out_price();
	return 1;
}
