#include <stdio.h>
int main(){
	int n,count=0;
	while(1){
		count++;
		scanf("%d",&n);
		if(n==250){
			printf("%d",count);
			break;
		}
	}
}
