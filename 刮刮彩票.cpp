#include <stdio.h>
int main(){
	int a[3][3],flag[10]={0},i,j,k,t=0,x,y,choice,sum=0;
	int money[19]={10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			flag[a[i][j]]=1;
		}
	}	
	for(i=1;i<10;i++){
		if(flag[i]==0){
			t=i;
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(a[i][j]==0){
				a[i][j]=t;
			}
		}
	}
	for(i=0;i<3;i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",a[x-1][y-1]);
	}
	scanf("%d",&choice);
	if(choice<=3){
		sum+=a[choice-1][1]+a[choice-1][2]+a[choice-1][0];
	}else if(choice>3&&choice<=6){
		sum+=a[0][choice-4]+a[1][choice-4]+a[2][choice-4];
	}else if(choice==7){
		sum+=a[0][0]+a[1][1]+a[2][2];
	}else if(choice==8){
		sum+=a[0][2]+a[1][1]+a[2][0];
	}
	printf("%d",money[sum-6]);
}
