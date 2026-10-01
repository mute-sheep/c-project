#include "list.h"

//字符串拷贝 
void my_strcpy(char *str1, char *str2) {
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

//计算字符串长度 
int my_strlen(char *s){
	int n = 0;
	while(*s != '\0'){
		s++;
		n++;
	}
	return n;
}

//字符串内容大小判断 
int my_strcmp(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 > *str2) {
            return 1;
        } else if (*str1 < *str2) {
            return -1;
        }
        str1++;
        str2++;
    }
    if (*str1 != '\0') {
        return 1;
    } else if (*str2 != '\0') {
        return -1;
    } else {
        return 0;
    }
}
