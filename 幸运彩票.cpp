#include<stdio.h>
int main(){
	int n,i,j,sum1,sum2;
	char num[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",&num);
		sum1=0,sum2=0;
		for(j=0;j<3;j++){
			sum1+=num[j]-'0';
		}
		for(j=3;j<6;j++){
			sum2+=num[j]-'0';
		}
		if(sum1==sum2){
			printf("You are lucky!\n");
		}else{
			printf("Wish you good luck.\n");
		}
	}
}
