#include <stdio.h>
#include <math.h>
int main(){
	int n,i,t=0,sum=0,min=0;
	scanf("%d",&n);
	char name[10005][20];
	double half_aver;
	int num[10005];
	for(i=0;i<n;i++){
		scanf("%s %d",name[i],&num[i]);
		sum+=num[i];
	}
	half_aver=0.5*sum/n;
	min=num[0];
	for(i=0;i<n;i++){
		if(fabs(min-half_aver)>fabs(num[i]-half_aver)){
			min=num[i];
			t=i;
		}
	}	
	printf("%.0f %s",half_aver,name[t]);
}
