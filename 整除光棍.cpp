#include <stdio.h>
int main(){
	long long int x,n=1;
	int count=1;
	scanf("%lld",&x);
	while(n<x){
		n=n*10+1;
		count++;
	}
	while(1){
		printf("%lld",n/x);
		if(n%x==0){
			break;
		}else{
			n=n%x*10+1;
			count++;
		}
	}
	printf(" %d",count);
}
