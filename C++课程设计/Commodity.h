#ifndef COMMODITY_H
#define COMMODITY_H
#define food_max 50
#define dress_max 50
#define appliance_max 50
#include"Date.h"
class Commodity//��Ʒ��������
{
	protected:
		int flag;//����ɾ����� 
		char com_name[20];//��Ʒ�� 
		int com_num;//��Ʒ���� 
		int com_type_num;//���ʹ��� 
		double com_in_price;//���� 
		double com_out_price;//�ۼ� 
		int repretroy;//��� 
		Date com_begin_time;//����ʱ�� 
		int com_deadline_time;//������ 
		char com_season[10];//���ڴ��� 
	public: 
		Commodity(int f=2,char name[20]={"0"},int num=0,int type_num=0,int y=0,int mon=0,int da=0,double in=0,double out=0,int re=0,int dt=0,char s[10]={"0"}){flag=f;strcpy(com_name,name);com_num=num;com_type_num=type_num;com_begin_time.year=y;com_begin_time.month=mon;com_begin_time.day=da;com_in_price=in;com_out_price=out;repretroy=re;com_deadline_time=dt;strcpy(com_season,s);}
		int operator=(Commodity &com);
		void set_com_name(){cin>>com_name;};//������Ʒ���� 
		void set_com_num(){cin>>com_num;};
		void set_con_type_num(){cin>>com_type_num;};
		void set_com_in_price(){cin>>com_in_price;};
		void set_com_out_price(){cin>>com_out_price;};
		void set_month(){cin>>repretroy;};
		void set_com_season(){cin>>com_season;};
		void set_com_deadline_time(){cin>>com_deadline_time;};
		int get_com_flag(){return(flag);};//��ȡ��Ʒ����
		char* get_com_name(){return(com_name);};
		int get_com_num(){return(com_num);};
		int get_com_type_num(){return(com_type_num);};
		double get_com_in_price(){return(com_in_price);};
		double get_com_out_price(){return(com_out_price);};
		int get_repretroy(){return(repretroy);};
		Date get_com_begin_time(){return(com_begin_time);};
		int get_com_deadline_time(){return(com_deadline_time);};
		char* get_com_season(){return(com_season);};
		int additem(){flag=0;if(flag==0)return 1;return 0;}//�����Ʒ��Ϣ 
		int delitem(){flag=1;if(flag==1)return 1;return 0;};// ɾ����Ʒ��Ϣ 
		int statechange();//���Ľ��ۣ��ۼ� 
		int findstate();//����� 	
		void show_com(); //�����Ʒ��Ϣ
		virtual void checkquantity();//�����


		
 };
 
#endif
