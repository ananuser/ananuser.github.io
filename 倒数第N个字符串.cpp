#include <stdio.h>
#include <math.h>
//����26���� 
int main(){
	int a,b,i,l,n;
	scanf("%d %d",&l,&n);
	n=pow(26,l)-n;  //������n���� 
	for(i=1;i<=l;i++){
		a=pow(26,l-i);
		b=n/a;
		printf("%c",b+'a');
		n%=a;
	}
}
