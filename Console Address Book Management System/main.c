#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[]) {
	FILE *fp = open_file();
	int choice;
	Node *L = initNode();
	
	if(!L){
		printf("头节点生成失败\n");
		return 1;
	}
	
	if(fp){
		getfile(L,fp);
		printf("数据加载成功\n");
	}

	while(1){
		if(!fp){
			break;
		}
		
		choice = main_menu();
		if(choice == 0)
			break;

		int fun;
		switch(choice){
			case 1:
				fun = add_menu();
				switch(fun){
					case 1:
						tail_insert(L);
						bubble_sort(L);
						break;
					case 2:
						mid_insert(L);
						break;	
				}
				break;
			case 2:
				fun = seek_menu();
				switch(fun){
					case 1:
						Search_for_surname(L);
						break;
					case 2:
						Search_for_id(L);
						break;
					case 3:
						Search_for_name(L);
						break;
					case 4:
						Search_for_telephone(L);
						break;
				}
				break;
			case 3:
				showNode(L);
				break;
			case 4:
				reverse_showNode(L);
				break;
		}
	}

	if(fp){
		putfile(L,fp);
	}
	freeNode(L);
	printf("欢迎你的下次使用\n");
	if(fp){
		fclose(fp);
		printf("文件已成功关闭\n");
	}
	return 0;
}
