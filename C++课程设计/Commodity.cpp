
#include"Commodity.h"
int Commodity::operator=(Commodity &com)//��ֵ���ط�����   ������Ʒ�����ֱ�Ӹ�ֵ
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


void Commodity::show_com()             //�����Ʒ��Ϣ
	{
	cout <<"��Ʒ����"<<com_name<<endl<<"��Ʒ���룺"<<com_num<<endl;
	if(com_type_num==1)cout<<"��Ʒ���ͣ�"<<"ʳƷ"<<endl; 
	if(com_type_num==2)cout<<"��Ʒ���ͣ�"<<"��װ"<<endl; 
	if(com_type_num==3)cout<<"��Ʒ���ͣ�"<<"����"<<endl; 
	cout<<"���� :"<<com_in_price<<endl<<"�ۼۣ�"<<com_out_price<<endl<<"���: "<<repretroy<<endl<<"����ʱ�� :"<<endl;com_begin_time.show();
	if(com_type_num==1)cout<<"ʳƷ������ :"<<com_deadline_time<<"��"<<endl;
	if(com_type_num==2)cout<<"��װ���ڣ�"<<com_season<<"��"<<endl;
	cout<<endl;
	}

	
void Commodity::checkquantity()
{
	
} 
int Commodity::findstate()//�����  
{
	cout<<"��Ʒ��棺"<<get_repretroy()<<endl;
	if(get_repretroy()<10)
	{
		cout<<"��治�㣡"<<endl; 
	}
} 
int Commodity::statechange()//������Ʒ���ۺ��ۼ�
{
	cout<<"��������Ʒ���ۣ�";set_com_in_price();
	cout<<"��������Ʒ�ۼۣ�";set_com_out_price();
	return 1;
}
