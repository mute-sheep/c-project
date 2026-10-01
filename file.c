#include "list.h"

//打开文件
FILE *open_file(){
	FILE *fp;
	printf("请选择模式\n");
	printf("1.查看通讯录\n");
	printf("2.创建一个新的通讯录\n");
	printf("0.退出\n");
	printf("！！！(创建一个新的通讯录会覆盖掉旧的通讯录)\n");
	printf("请选择模式\n");
	int choice = legal_input_int(0,2);
 	if(choice == 1){
        fp = fopen("contacts.txt", "rb+");
        if(fp == NULL){
            fp = fopen("contacts.txt", "wb");
            if(fp != NULL){
                fclose(fp);
            }
            fp = fopen("contacts.txt", "rb+");
        }
    }
    else if(choice == 2){
        fp = fopen("contacts.txt", "wb");
        if(fp != NULL){
            fclose(fp);
        }
        fp = fopen("contacts.txt", "rb+");
    }
    else{
        return NULL;
    }
	if(!fp){
		printf("打开失败\n");
		return NULL;
	}
	printf("打开成功\n");
	return fp;
}

//获取文件内容  
void getfile(Node *L,FILE *fp){
	if(!L || !fp){
		printf("打开失败\n");
		return;
	}
	rewind(fp);
	Node *tail = position(L);
	Node data;
	while(fread(&data,sizeof(Node),1,fp) == 1){
		Node *q = (Node *)malloc(sizeof(Node));
		if(!q){
			printf("内存分配失败\n");
			return;
		}
		q->id = data.id;
		my_strcpy(q->name, data.name);
		my_strcpy(q->telephone, data.telephone);
		my_strcpy(q->wechat, data.wechat);
		my_strcpy(q->address, data.address);
		q->birth = data.birth;
		q->next = NULL;
		tail->next = q;
		tail = q;
		L->length++;
	}
}

//将链表写入文件 
void putfile(Node *L, FILE *fp) {
    if (!L || !fp) {
        printf("保存失败：链表或文件不存在\n");
        return;
    }
    rewind(fp);
    Node *p = L->next;
    while (p) {
        fwrite(p, sizeof(Node), 1, fp);
        p = p->next;
    }
    fflush(fp);
    printf("保存成功！\n");
}
