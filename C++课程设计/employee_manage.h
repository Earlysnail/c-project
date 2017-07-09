#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H
#include"saleman.h"
#include"manager.h"
#include"warehouseman.h"

class employee_manage//���¹������� _��ȫ��Ա����Ϣ���в���
{
	private:
		int saleman_total;
		int manager_total; 
		int	warehouseman_total;
		saleman saleman_sum[saleman_max];
		manager manager_sum[manager_max];
		warehouseman warehouseman_sum[warehouseman_max];
		
	public:
		employee_manage();
		~employee_manage();
		int addemployee(saleman &sale);//���Ա����Ϣ
		int addemployee(manager &sale);
		int addemployee(warehouseman &sale);
		int delemployee(employee *emp);// ɾ��Ա����Ϣ
		void show();  //��ʾȫ��Ա����Ϣ 
		employee *query(char name[20]);//����Ա����Ϣ 
		employee *query(double num);
		employee *query(int month);
		int statechange(employee *emp);//����Ա�����飬ְ����Ϣ 
		int findstate(employee *emp);//��ѯԱ��ְ����� 
		void recordsalary(employee *emp);//��¼Ա������ */
		void emp_manage_menu();	//���¹���˵�	
};

#endif
