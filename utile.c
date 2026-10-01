#include "list.h"

//判断数字输入是否合法
int legal_input_int(int min,int max){
	printf("请输入数字\n");
	int n;
	while(1){
		if(scanf("%d",&n) != 1){
			printf("非法输入\n");
			while(getchar() != '\n');
			continue;
		}
		if(n < min || n > max){
			printf("输入越界(请输入%d-%d)\n",min,max);
			continue;
		}
		printf("\n");
		return n;
	}
}

// 校验是否为纯数字
int is_all_digit(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

//判断电话号码是否合法 
char *legal_input_telephone(){
	char *telephone = (char *)malloc(20 * sizeof(char));
	if (telephone == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
	while(1){
		printf("请输入电话\n");
		scanf("%s",telephone);
		if(my_strlen(telephone) != 11){
			printf("电话号码格式错误\n");
			printf("请输入11位的电话号码\n");
			while(getchar() != '\n');
			continue;	
	}
	    if (!is_all_digit(telephone)) {
            printf("电话号码必须是纯数字！\n");
            continue;
        }
		break;
	}
	return telephone;
}

//判断单个字符输入是否合法
int legal_input_single_character() {
    char s;
    printf("请输入单个字符：");
    while (1) {
        while ((s = getchar()) != EOF && (s == '\n' || s == ' ' || s == '\t'));
        
        if (s == EOF) {
            printf("输入错误\n");
            return 0;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        printf("\n");
        return (int)s;
    }
}

//判断微信号是否合法
char *legal_input_wechat() {
    char *wechat = (char *)malloc(50 * sizeof(char));
    char *p = wechat;  
    while (1) {
        printf("请输入微信号(必须由数字、大小写字母、_组成)\n");
        scanf("%s", wechat);
        int flag = 0;
        p = wechat;  
        for (int i = 0; p[i] != '\0'; i++) {
            if (!((p[i] >= '0' && p[i] <= '9') ||
                  (p[i] >= 'a' && p[i] <= 'z') ||
                  (p[i] >= 'A' && p[i] <= 'Z') ||
                  (p[i] == '_'))) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return wechat; 
        }
        printf("微信号格式出错！请重新输入\n");
    }
}

//国家选择
char *country(){
	const char *countries[] = {
    "中国", "朝鲜", "韩国", "日本", "蒙古",
    "越南", "老挝", "柬埔寨", "泰国", "缅甸",
    "马来西亚", "新加坡", "文莱", "印度尼西亚", "菲律宾",
    "印度", "巴基斯坦", "孟加拉国", "尼泊尔", "不丹",
    "斯里兰卡", "马尔代夫", "阿富汗", "伊拉克", "伊朗",
    "叙利亚", "黎巴嫩", "约旦", "沙特阿拉伯", "巴林",
    "卡塔尔", "科威特", "阿联酋", "阿曼", "土耳其",
    "以色列", "埃及", "南非", "尼日利亚", "肯尼亚",
    "英国", "法国", "德国", "意大利", "俄罗斯",
    "加拿大", "巴西", "阿根廷", "澳大利亚", "新西兰"
};
    printf("===== 请选择国家 =====\n");
    int country_count = sizeof(countries)/sizeof(*countries);
    for (int i = 0; i < country_count; i++) {
        printf("%2d: %s  ", i + 1, countries[i]); 
        if ((i + 1) % 5 == 0) {
            printf("\n");  
        }
    }

    int select = legal_input_int(1, 50);
    return (char *)countries[select - 1];
} 
