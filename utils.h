#ifndef UTILS_H
#define UTILS_H

#include<stdio.h>
#include<stdlib.h>

// 日期嵌套结构体
typedef struct Date {
    int year;
    int month;
    int day;
} Date;

// 联系人核心结构体
typedef struct node {
    int id;        
    char name[20];      
    char telephone[15];     
    char wechat[20];    
    char address[10];   
    Date birth;         
    struct node* next;
    int length;
}Node;


#endif
