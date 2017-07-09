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
		int additem(food &food);//添加商品信息
		int additem(dress &dress);
		int additem(appliance &app);
		int delitem(Commodity *com);// 删除商品信息 
		void show();  //显示全部商品信息 
		Commodity *query(char name[20]);//查找商品信息 
		Commodity *query(double num);
		int statechange(Commodity *com);//更改商品进价，售价 
		int findstate(Commodity *com);//查询商品库存 
		void checkquantity(Commodity *com);//检查商品是否过期 */	
		void com_manage_menu();	//商品管理菜单	
};



#endif
