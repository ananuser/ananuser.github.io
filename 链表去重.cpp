#include <stdio.h>
#include <math.h>
#define max 100005
int first,n,i,j,k,t,cnt_a=0,cnt_b=0;
int num[max],loc[max],visit[max]={0},a[max],b[max];
int main(){
	scanf("%d %d",&first,&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		scanf("%d %d",&num[t],&loc[t]);
	}
	k=first;
	while(k!=-1){
		t=abs(num[k]);
		if(visit[t]==0){
			visit[t]=1;
			a[cnt_a++]=k;
		}else{
			b[cnt_b++]=k;
		}
		k=loc[k];
	}
	for(i=0;i<cnt_a-1;i++){
		printf("%05d %d %05d\n",a[i],num[a[i]],a[i+1]);
	}
	printf("%05d %d -1\n",a[cnt_a-1],num[a[cnt_a-1]]);
	if(cnt_b){
		for(i=0;i<cnt_b-1;i++){
			printf("%05d %d %05d\n",b[i],num[b[i]],b[i+	1]);
		}	
		printf("%05d %d -1\n",b[cnt_b-1],num[b[cnt_b-1]]);
	}
} 
