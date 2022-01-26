#include <stdio.h>
#include <string.h>
int main(){
	char a[10005],b[10005];
	int i;
	gets(a);
	gets(b);
	int t[300];
	for(i=0;i<strlen(b);i++){
		t[b[i]]=1; //第二行出现的元素都定为1 
	}
	for(i=0;i<strlen(a);i++){
		if(t[a[i]]==0){  //如果没出现过就输出 
			printf("%c",a[i]);
		}
	}
}
