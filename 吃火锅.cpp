#include <stdio.h>
#include <string.h>
int main(){
	char str[101],flag[20]="chi1 huo3 guo1";
	int flag1=0,count=0,flag2=0;
	while(1){
		gets(str);
		if(strcmp(str,".")==0){
			break;
		}
		count++;
		if(strstr(str,flag)!=NULL){
			flag1++;
			if(flag2==0){
				flag2=count;
			}
		}
	}
	printf("%d\n",count);
	if(flag1==0){
		printf("-_-#");
	}else{
		printf("%d %d",flag2,flag1);
	}
}
