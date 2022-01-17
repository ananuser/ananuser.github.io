#include <stdio.h>
#include <string.h>
int main(){
	char a[10001];
	scanf("%s",a);
	int i,g=10,p=0,l=0,t=0,flag=1;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='g'||a[i]=='G'){
			g++;
		}
		if(a[i]=='p'||a[i]=='P'){
			p++;
		}
		if(a[i]=='l'||a[i]=='L'){
			l++;
		}
		if(a[i]=='t'||a[i]=='T'){
			t++;
		}
	}
	while(flag){
		flag=0;
		if(g){
			printf("G");
			g--;
			flag=1;
		}
		if(p){
			printf("P");
			p--;
			flag=1;
		}
		if(l){
			printf("L");
			l--;
			flag=1;
		}
		if(t){
			printf("T");
			t--;
			flag=1;
		}
	}
}
