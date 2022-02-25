#include <stdio.h>
int main(){
	int a1,sum,a2,c=3,n,i,j,x[1001];
	scanf("%d %d %d",&a1,&a2,&n);
	x[1]=a1,x[2]=a2;
	for(i=1;i<=n;i++){
		sum=x[i]*x[i+1];
		if(sum<10){
			x[c++]=sum;
		}else{
			x[c++]=sum/10;
			x[c++]=sum%10;
		}
		if(c>n){
			break;
		}
	}
	printf("%d",a1);
	for(j=2;j<=n;j++){
		printf(" %d",x[j]);
	}
}
