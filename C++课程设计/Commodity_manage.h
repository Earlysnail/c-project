#ifndef COMMODITY_MANAGE_H
#define COMMODITY_MANAGE_H
#include"food.h"
#include"dress.h"
#include"appliance.h"
class Commodity_manage
{
	private:
		Commodity com;
		int food_total;
		int dress_total; 
		int	appliance_total;
		food food_sum[food_max];
		dress dress_sum[dress_max];
		appliance appliance_sum[appliance_max];
		
	public:
		Commodity_manage();
		~Commodity_manage();
		int additem(food &food);//�����Ʒ��Ϣ
		int additem(dress &dress);
		int additem(appliance &app);
		int delitem(Commodity *com);// ɾ����Ʒ��Ϣ 
		void show();  //��ʾȫ����Ʒ��Ϣ 
		Commodity *query(char name[20]);//������Ʒ��Ϣ 
		Commodity *query(double num);
		int statechange(Commodity *com);//������Ʒ���ۣ��ۼ� 
		int findstate(Commodity *com);//��ѯ��Ʒ��� 
		void checkquantity(Commodity *com);//�����Ʒ�Ƿ���� */	
		void com_manage_menu();	//��Ʒ����˵�	
};



#endif
