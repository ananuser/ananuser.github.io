#include <stdio.h>
int main(){
	int i,j,h,m,n,count,t,id;
	int arr[1005][2];
	char s;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		count=0,t=0;
		for(j=0;j<1005;j++){
			arr[j][0]=0;
			arr[j][1]=0;
		}
		scanf("%d %c %d:%d",&id,&s,&h,&m);
		while(id){
			if(s=='S'){
				arr[id][0]=1;
				arr[id][1]=h*60+m;
			}else if(s=='E'&&arr[id][0]==1){
				t+=h*60+m-arr[id][1];
				arr[id][0]=0;
				count++;
			}
			scanf("%d %c %d:%d",&id,&s,&h,&m);
		}
		if(count>1){
			printf("%d %.0lf\n",count,(double)t/count);
		}else{
			printf("%d %d\n",count,t);
		}
	}
}
