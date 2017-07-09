#ifndef APPLIANCE_H
#define APPLIANCE_H
#include"Commodity.h"
class  appliance:public Commodity//电器商品类 
{
	public:
	appliance(){}
	appliance(int f,char name[20],int num,int type_num,int y,int mon,int da,double in,double out,int re,int dt,char s[10]):Commodity(f,name,num,type_num,y,mon,da,in,out,re,dt,s){}
	int operator=(Commodity &com);
	virtual void checkquantity();
	
}; 

#endif
