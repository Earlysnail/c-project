#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include<cstdlib>
#include<cstdio>
using namespace std;
class Date//������
{
	public:
		int year,month,day;
		Date(int y=0,int mon=0,int da=0){year=y;month=mon;day=da;}	
		void show(){
			cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
		}
}; 



#endif
