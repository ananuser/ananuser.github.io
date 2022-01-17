#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int i,j,k,id,m;
	int count=0;
	int r[100000]={0};
	for(i=0;i<n;i++){
		scanf("%d",&k);
		for(j=0;j<k;j++){
			scanf("%d",&id);
			if(k>1){
				r[id]=id;
			}
		}
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&id);
		if(!r[id]){
			count==0?printf("%05d",id):printf(" %05d",id);
			count++;
			r[id]=id;  //把第一次没出现的放进去，当第二次出现则不会再显示 
		}
	}
	if(count==0){
		printf("No one is handsome");
	}
}
