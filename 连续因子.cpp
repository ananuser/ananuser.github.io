#include <stdio.h>
#include <math.h>
int main(){
	long long int n,i,j,num,count,start=0,max=0;
	scanf("%lld",&n);
	for(i=2;i<sqrt(n);i++){
		num=1;
		count=0;
		for(j=i;n%(num*j)==0;j++){
			count++;
			num*=j;
		}
		if(count>max){
			start=i;
			max=count;
		}
	}
	if(max==0){
		printf("1\n");
		printf("%lld\n",n);
	}else{
		printf("%lld\n",max);
		for(i=start;i<start+max-1;i++){
			printf("%lld*",i);
		}
		printf("%lld\n",i);
	}
}
