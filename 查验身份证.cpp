#include <stdio.h>
int main(){
	char x[19];
	int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char b[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	int z,i,n,j,flag=0,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		sum=0;
		scanf("%s",x);
		for(j=0;j<17;j++){
			sum+=(x[j]-'0')*a[j];
		}
		z=sum%11;
		if(b[z]!=x[17]){
			printf("%s\n",x);
			flag=1;
		}
	}
	if(!flag){
		printf("All passed");
	}
}
