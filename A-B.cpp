#include <stdio.h>
#include <string.h>
int main(){
	char a[10005],b[10005];
	int i;
	gets(a);
	gets(b);
	int t[300];
	for(i=0;i<strlen(b);i++){
		t[b[i]]=1; //�ڶ��г��ֵ�Ԫ�ض���Ϊ1 
	}
	for(i=0;i<strlen(a);i++){
		if(t[a[i]]==0){  //���û���ֹ������ 
			printf("%c",a[i]);
		}
	}
}
