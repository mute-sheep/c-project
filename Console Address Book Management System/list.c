#include "list.h"

//创建头节点 
Node *initNode(){
	Node *head = (Node *)malloc(sizeof(Node));
	if(!head){
		printf("内存分配失败\n");
		return NULL;
	}
	head->id = 0;
	head->name[0] = '\0';
	head->telephone[0] = '\0';
	head->wechat[0] = '\0';
	head->address[0] = '\0';
	head->next = NULL;
	head->length = 0;
	return head;
} 

//获取尾节点位置 
Node *position(Node *L){
	if(!L){
		printf("链表不存在"); 
		return NULL;
	}
	Node *p = L;
	while(p->next != NULL)
		p = p->next;
	return p;
}

//信息输入
void insert(Node *L){
	if(!L){
		printf("链表不存在\n");
		return;
	}
	Node *q=L;

	char *tel = legal_input_telephone();
	my_strcpy(q->telephone, tel);
	free(tel);

	char *wx = legal_input_wechat();
	my_strcpy(q->wechat, wx);
	free(wx); 

	my_strcpy(q->address,country());
	printf("请输入生日\n");
	printf("年份（1000-2030）：\n");
	int year = legal_input_int(1000,2030);
	printf("月份:");
	int month = legal_input_int(1,12);
	int day;
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("日期(1-31)");
			day=legal_input_int(1,31);
			break;
		case 2:
			if( (year%4==0 && year%100!=0) || (year%400==0) ){
				printf("日期(1-29)");
				day=legal_input_int(1,29);
			}
			else{
				printf("日期(1-28)");
				day=legal_input_int(1,28);
			}
			break;
		default:
			printf("日期(1-30)");
			day=legal_input_int(1,30);
			break;
		}
		q->birth.year=year;
		q->birth.month=month;
		q->birth.day=day;
		return;				 
}

//尾插法 
void tail_insert(Node *L){
	if(!L){
		printf("链表不存在\n");
		return; 
	}
	while(1){
		Node *q = (Node *)malloc(sizeof(Node));
		if(!q){
			printf("内存分配\n");
			return;
		} 
		printf("输入-1结束\n");
		printf("请输入姓名\n");
		scanf("%s",q->name);
		if(my_strcmp(q->name,"-1") == 0){
			free(q);
			printf("输入结束，本次一共输入%d名联系人\n",L->length);
			printf("\n");
			return;
		}
		insert(q);
		Node *tail = position(L);
		tail->next = q;
		q->next = NULL;
		L->length++;
	}
	return;
}

//按姓名排序 
void bubble_sort(Node *L){
if(!L || !L->next){
		return;
	}
	int changed;
	Node *p;
	Node *last = NULL;
	do{
		changed = 0;
		p = L->next;
		while(p->next != last){
			if(my_strcmp(p->name, p->next->name) > 0){
				Node temp = *p;
				my_strcpy(p->name, p->next->name);
				my_strcpy(p->telephone, p->next->telephone);
				my_strcpy(p->wechat, p->next->wechat);
				my_strcpy(p->address, p->next->address);
				p->birth = p->next->birth;

				my_strcpy(p->next->name, temp.name);
				my_strcpy(p->next->telephone, temp.telephone);
				my_strcpy(p->next->wechat, temp.wechat);
				my_strcpy(p->next->address, temp.address);
				p->next->birth = temp.birth;
				changed = 1;
			}
			p = p->next;
		}
		last = p;
	}while(changed);
	int i=0;
	Node *head = L->next;
	while(head != NULL){
		i++;
		head->id = i;
		head = head->next;
	}
}

//指定位置插入 
void mid_insert(Node *L){
	if(L->length == 0){
	    printf("暂无联系人，请先添加！\n");
	    return;
	}
	printf("现已有通讯录人数为%d\n",L->length);
	printf("请输入插入的位置\n");
	int pos = legal_input_int(1,L->length);
	Node *p = L;
	for(int i=0;i<pos-1;i++)
		p = p->next; 
	Node *q = (Node *)malloc(sizeof(Node));
	printf("请输入姓名\n");
	scanf("%s",q->name);
	insert(q);
	q->next = p->next;
	p->next = q;
	L->length++; 
	bubble_sort(L);
}

//修改联系人信息 
void changeNode(Node *L,char *s){
	if(!L){
		printf("链表不存在\n");
		return;
	}
	Node *p = L->next;
	while(p){
		if(my_strcmp(p->name,s) == 0 || my_strcmp(p->telephone,s) == 0){
			printf("请输入新的姓名\n");
			scanf("%s",p->name);
			insert(p);
			bubble_sort(L);
			printf("修改成功！\n");
			printf("\n");
			return;
		}
		p = p->next;
	}
	printf("未找到此人\n");
}

//删除联系人 
void delNode(Node *L,char *s){
	if(!L){
		printf("链表不存在\n");
		return;
	}
	Node *p=L;
	while(p->next != NULL){
		if(my_strcmp(p->next->name,s) == 0 || my_strcmp(p->next->telephone,s) == 0){
				Node *q=p->next;
				printf("你要删除的人是: %s\n",q->name);
				printf("电话: %s\n",q->telephone);
				printf("确定要删除\n");
				printf("1.确定\n");
				printf("2.我后悔了\n");
				if(legal_input_int(1,2) == 2)
					return;

				p->next = q->next;
				free(q);
				L->length--;
				printf("删除成功\n");
				printf("\n");
				bubble_sort(L);
				return;
		}
		p = p->next;
	}
	printf("未找到此人\n");
}

//修改删除调用
void change_or_del(Node *L, Node *cur) {
	if (!cur) {
		printf("数据无效\n");
		return;
	}
	printf("1.修改信息\n");
	printf("2.删除这个信息\n");
	printf("0.不做操作\n");
	int choice = legal_input_int(0, 2);

	switch (choice) {
		case 1:
			changeNode(L, cur->name);
			break;
		case 2:
			delNode(L, cur->name);
			break;
	}
}

//查找联系人

//姓氏查找 
void Search_for_surname(Node *L){
	printf("请输入姓氏，会显示出全部该姓氏的人\n");
	char s = legal_input_single_character();
	Node *p = L->next;
	int flag = 0;
	while(p){
		if(p->name[0] == s){
			printf("序号：%d\n",p->id);
			printf("姓名：%s\n",p->name);
			printf("电话：%s\n",p->telephone);
			printf("微信号:%s\n",p->wechat);
			printf("地址：%s\n",p->address);
			printf("生日: %d年 %d月 %d日\n",p->birth.year,p->birth.month,p->birth.day);
			printf("\n");
			flag = 1;
		}
		p = p->next;
	}
	if(flag == 0)
		printf("未找到此姓氏的人\n");
	return;
}

//序号查找
void Search_for_id(Node *L){
	if(!L || L->length == 0){
		printf("无联系人\n");
		return;
	}
	printf("请输入查找人的序号（目前最大为%d）\n",L->length);
	int n = legal_input_int(1,L->length);
	Node *p = L->next;
	for(int i=1;i < n;i++)
		p = p->next;

	printf("序号：%d\n",p->id);
	printf("姓名：%s\n",p->name);
	printf("电话：%s\n",p->telephone);
	printf("微信号:%s\n",p->wechat);
	printf("地址：%s\n",p->address);
	printf("生日: %d年 %d月 %d日\n",p->birth.year,p->birth.month,p->birth.day);
	printf("\n");
	change_or_del(L, p); 
	return;
}

//姓名查找
void Search_for_name(Node *L){
	if(!L || !L->next){
		printf("无联系人\n");
		return;
	}
	printf("请输入查找人的姓名\n");
	char name[20];
	scanf("%s",name);
	Node *p = L->next;

	while(p){
		if(my_strcmp(p->name,name) == 0){
			printf("序号：%d\n",p->id);
			printf("姓名:%s\n",p->name);
			printf("电话:%s\n",p->telephone);
			printf("微信号:%s\n",p->wechat);
			printf("地址:%s\n",p->address);
			printf("生日: %d年 %d月 %d日\n",p->birth.year,p->birth.month,p->birth.day);
			printf("\n");
			change_or_del(L, p);
			return;
		}
		p = p->next;
	}
	printf("未找到%s\n",name);
	return;
}

//电话查找
void Search_for_telephone(Node *L){
	if(!L || !L->next){
		printf("无联系人\n");
		return;
	}
	printf("请输入查找人的电话\n");
	char telephone[15];
	char *tmp_tel = legal_input_telephone();
	my_strcpy(telephone, tmp_tel);
	free(tmp_tel);
	Node *p = L->next;

	while(p){
		if(my_strcmp(p->telephone,telephone) == 0){
			printf("序号：%d\n",p->id);
			printf("姓名:%s\n",p->name);
			printf("电话:%s\n",p->telephone);
			printf("微信号:%s\n",p->wechat);
			printf("地址:%s\n",p->address);
			printf("生日: %d年 %d月 %d日\n",p->birth.year,p->birth.month,p->birth.day);
			printf("\n");
			change_or_del(L, p);
			return;
		}
		p = p->next;
	}
	printf("未找到\n");
	return;
}


//遍历 
void showNode(Node *L){
if(!L || !L->next){
		printf("暂无联系人\n");
		return;
	}
	Node *p = L->next;
	printf("===== 所有联系人 =====\n");
	while(p){
		printf("序号:%-4d 姓名：%s\n",p->id,p->name);
		p = p->next;
	}
	while(1){
		printf("输入序号查看详情(0退出)\n");
		int n = legal_input_int(0,L->length);
		if(n == 0)
			return;

		Node *q = L->next;
		for(int i=1;i<n;i++){
		    q = q->next;
		}
		printf("\n===== 详情 =====\n");
		printf("序号：%d\n",q->id);
		printf("姓名:%s\n",q->name);
		printf("电话:%s\n",q->telephone);
		printf("微信号:%s\n",q->wechat);
		printf("地址:%s\n",q->address);
		printf("生日: %d年 %d月 %d日\n",q->birth.year,q->birth.month,q->birth.day);
		printf("\n");
		change_or_del(L,q);
		return;
	}
}

//逆序遍历 
void reversePrint(Node *p) {
    if (p == NULL) return;
    reversePrint(p->next); 
    printf("序号:%-4d 姓名：%s\n", p->id, p->name);
}

// 逆序显示所有联系人
void reverse_showNode(Node *L) {
    if (!L || !L->next) {
        printf("暂无联系人\n");
        return;
    }
    printf("===== 所有联系人（逆序）=====\n");
    while (1) {
        printf("输入序号查看详情(0退出)\n");
        int n = legal_input_int(0, L->length);
        if (n == 0) return;
        Node *q = L->next;
        for (int i = 1; i < n; i++) {
            q = q->next;
        }

        printf("\n===== 详情 =====\n");
        printf("序号：%d\n", q->id);
        printf("姓名:%s\n", q->name);
        printf("电话:%s\n", q->telephone);
        printf("微信号:%s\n", q->wechat);
        printf("地址:%s\n", q->address);
        printf("生日: %d年 %d月 %d日\n", q->birth.year, q->birth.month, q->birth.day);
        printf("\n");

        change_or_del(L, q);
        return;
    }
}

//链表释放 
void freeNode(Node *L){
	Node *p = L;
	Node *q = NULL;
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	printf("链表内存已全部释放！\n");
}
