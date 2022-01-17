#include <stdio.h>
#include <string.h>
int main(){
	char n[50];
	int i,b=0,c=1;
	float f,a=1.0;
	scanf("%s",n);
	int d=strlen(n);
	for(i=0;i<strlen(n);i++){
		if(n[0]=='-'){
			a=1.5;
			d=strlen(n)-1;
		}
		if(n[i]-'0'==2){
			b++;
		}
		if(n[strlen(n)-1]%2==0){
			c=2;
		}
	}
	f=b*a*c/d*100;
	printf("%.2f%%",f);
}
