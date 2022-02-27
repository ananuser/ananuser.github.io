#include <stdio.h>
int main(){
	int a[5],i,a_max=0,pre_max,diff_max,count1=0,t1=0,count2=0,t2=6;
	for(i=1;i<5;i++){
		scanf("%d",&a[i]);
		if(a_max<a[i]){
			a_max=a[i];
		}
	}
	scanf("%d %d",&pre_max,&diff_max);
	for(i=1;i<5;i++){
		if(a_max-a[i]>diff_max){
			count1++;
		}
		if(count1==1){
			t1=i;
			count1=2;
		}
	}
	for(i=1;i<5;i++){
		if(a[i]<pre_max){
			count2++;
		}
		if(count2==1){
			t2=i;
			count2=2;
		}
	}
	if(count1==0&&count2==0){
		printf("Normal");
	}else if(count1==2&&count2==0){
		printf("Warning: please check #%d!",t1);
	}else if(count2==2&&count1==2&&t1==t2){
		printf("Warning: please check #%d!",t2);
	}else if(count1>2||count2>2){
		printf("Warning: please check all the tires!");
	}else if(count2==2&&count1==0){
		printf("Warning: please check #%d!",t2);
	}
}
