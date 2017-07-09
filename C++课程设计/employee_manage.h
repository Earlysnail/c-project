#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H
#include"saleman.h"
#include"manager.h"
#include"warehouseman.h"

class employee_manage//人事管理总类 _对全体员工信息进行操作
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
		int addemployee(saleman &sale);//添加员工信息
		int addemployee(manager &sale);
		int addemployee(warehouseman &sale);
		int delemployee(employee *emp);// 删除员工信息
		void show();  //显示全部员工信息 
		employee *query(char name[20]);//查找员工信息 
		employee *query(double num);
		employee *query(int month);
		int statechange(employee *emp);//更改员工柜组，职务信息 
		int findstate(employee *emp);//查询员工职务代码 
		void recordsalary(employee *emp);//记录员工工资 */
		void emp_manage_menu();	//人事管理菜单	
};

#endif
