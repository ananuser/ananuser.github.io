#include <stdio.h>
#include <math.h>
//看做26进制 
int main(){
	int a,b,i,l,n;
	scanf("%d %d",&l,&n);
	n=pow(26,l)-n;  //倒数第n个数 
	for(i=1;i<=l;i++){
		a=pow(26,l-i);
		b=n/a;
		printf("%c",b+'a');
		n%=a;
	}
}
