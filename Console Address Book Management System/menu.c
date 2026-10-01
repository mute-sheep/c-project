#include "list.h"

//主菜单
int main_menu(){
	printf("=====主菜单=====\n");
	printf("1.添加联系人\n");
	printf("2.查找联系人\n");
	printf("3.所有联系人\n");
	printf("4.倒序所有联系人\n");
	printf("0.退出\n");	
	printf("请选择模式\n");
	return legal_input_int(0,4);
}

//添加菜单
int add_menu(){
	printf("=====添加菜单=====\n");
	printf("1.自动添加(按照姓名进行排序)\n");
	printf("2.指定位置添加\n");
	printf("0.退出\n");
	printf("请选择模式\n");
	return legal_input_int(0,2); 
} 

//查找菜单 
int seek_menu(){
	printf("=====查找=====\n");
	printf("1.姓氏查找\n");
	printf("2.序号精确查找\n");
	printf("3.姓名精确查找\n");
	printf("4.电话精确查找\n");
	printf("0.退出\n");
	printf("请选择功能\n");
	return legal_input_int(0,4);
} 
