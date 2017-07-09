#ifndef FOOD_H
#define FOOD_H
#include"Commodity.h"
 class food:public Commodity//食物商品类 
{	
	public:
		food(){}
		food(int f,char name[20],int num,int type_num,int y,int mon,int da,double in,double out,int re,int dt,char s[10]):Commodity(f,name,num,type_num,y,mon,da,in,out,re,dt,s){}
		int operator=(Commodity &com);
		virtual void checkquantity();
};

#endif
