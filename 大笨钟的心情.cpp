#include <stdio.h>
int main(){
	int i,clock[24],n=0;
	for(i=0;i<24;i++){
		scanf("%d",&clock[i]);
	}
	scanf("%d",&n);
	while(n>=0&&n<=23){
		if(clock[n]>50){
			printf("%d Yes\n",clock[n]);
		}else{
			printf("%d No\n",clock[n]);
		}
		scanf("%d",&n);
	}
}
