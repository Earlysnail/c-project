#ifndef COMMODITY_H
#define COMMODITY_H
#define food_max 50
#define dress_max 50
#define appliance_max 50
#include"Date.h"
class Commodity//商品管理总类
{
	protected:
		int flag;//设置删除标记 
		char com_name[20];//商品名 
		int com_num;//商品编码 
		int com_type_num;//类型代码 
		double com_in_price;//进价 
		double com_out_price;//售价 
		int repretroy;//库存 
		Date com_begin_time;//进货时间 
		int com_deadline_time;//保质期 
		char com_season[10];//季节代码 
	public: 
		Commodity(int f=2,char name[20]={"0"},int num=0,int type_num=0,int y=0,int mon=0,int da=0,double in=0,double out=0,int re=0,int dt=0,char s[10]={"0"}){flag=f;strcpy(com_name,name);com_num=num;com_type_num=type_num;com_begin_time.year=y;com_begin_time.month=mon;com_begin_time.day=da;com_in_price=in;com_out_price=out;repretroy=re;com_deadline_time=dt;strcpy(com_season,s);}
		int operator=(Commodity &com);
		void set_com_name(){cin>>com_name;};//更改商品属性 
		void set_com_num(){cin>>com_num;};
		void set_con_type_num(){cin>>com_type_num;};
		void set_com_in_price(){cin>>com_in_price;};
		void set_com_out_price(){cin>>com_out_price;};
		void set_month(){cin>>repretroy;};
		void set_com_season(){cin>>com_season;};
		void set_com_deadline_time(){cin>>com_deadline_time;};
		int get_com_flag(){return(flag);};//获取商品属性
		char* get_com_name(){return(com_name);};
		int get_com_num(){return(com_num);};
		int get_com_type_num(){return(com_type_num);};
		double get_com_in_price(){return(com_in_price);};
		double get_com_out_price(){return(com_out_price);};
		int get_repretroy(){return(repretroy);};
		Date get_com_begin_time(){return(com_begin_time);};
		int get_com_deadline_time(){return(com_deadline_time);};
		char* get_com_season(){return(com_season);};
		int additem(){flag=0;if(flag==0)return 1;return 0;}//添加商品信息 
		int delitem(){flag=1;if(flag==1)return 1;return 0;};// 删除商品信息 
		int statechange();//更改进价，售价 
		int findstate();//检查库存 	
		void show_com(); //输出商品信息
		virtual void checkquantity();//检查库存


		
 };
 
#endif
