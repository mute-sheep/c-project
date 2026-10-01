#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

//数字非法判断 
int legal_input_int(int min,int max);
// 校验电话号码是否为纯数字
int is_all_digit(const char *str);
//电话号码非法判断 
char *legal_input_telephone();
//单个字符非法判断 
int legal_input_single_character();
//微信号非法输入 
char *legal_input_wechat();
//信息输入
void insert(Node *L); 
//国家选择 
char *country();
//字符串内容大小判断 
int my_strcmp(char *str1, char *str2);
//字符串拷贝 
void my_strcpy(char *str1, char *str2);
//计算字符串长度 
int my_strlen(char *s);
//创建头节点 
Node *initNode(); 
//打开文件 
FILE *open_file();
//写入文件 
void putfile(Node *L, FILE *fp); 
//主菜单 
int main_menu();
//添加菜单 
int add_menu();
//尾插法前置 
Node *position(Node *L);
//尾插法 
void tail_insert(Node *L);
//链表排序 
void bubble_sort(Node *L);
//获取文件内容到链表 
void getfile(Node *L,FILE *fp);
//修改联系人信息 
void changeNode(Node *L,char *s);
//删除联系人信息
void delNode(Node *L,char *s); 
//删除修改
void change_or_del(Node *L, Node *cur);
//姓氏查找 
void Search_for_surname(Node *L);
//序号查找
void Search_for_id(Node *L);
//姓名查找
void Search_for_name(Node *L); 
//电话查找 
void Search_for_telephone(Node *L);
//遍历 
void showNode(Node *L);
//逆序遍历 
void reversePrint(Node *p);
//倒叙遍历 
void reverse_showNode(Node *L);
//链表释放 
void freeNode(Node *L); 
#endif
