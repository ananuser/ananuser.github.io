#include <stdio.h>
#include <string.h>
int main(){
	int i,j;
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int b[10]={0};
	char n[1002];
	scanf("%s",n);
	for(i=0;i<strlen(n);i++){
		for(j=0;j<10;j++){
			if(a[j]==n[i]-'0'){
				b[j]++;
			}
		}
	}
	for(j=0;j<10;j++){
		if(b[j]!=0){
			printf("%d:%d\n",j,b[j]);
		}
	}
}
