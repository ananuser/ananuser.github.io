#include <stdio.h>
#include <math.h>
int main(){
	int N,M,i,j,num=0,sum=1;
	scanf("%d %d",&N,&M);
	char a[40];
	for(i=0;i<M;i++){
		num=pow(2,N-1);
		sum=1;
		scanf("%s",a);
		for(j=0;j<N;j++){
			if(a[j]=='n'){
				sum+=num;
			}
			num/=2;
		}
		printf("%d\n",sum);
	}
}
