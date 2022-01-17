#include <stdio.h>
#include <string.h>
int main(){
	int k,y,n,i;
	int b[4]; //存放四位个数 
	scanf("%d %d",&y,&n);
	for(i=y;i<10000;i++){ //i为要寻找的满足条件的年份 
		k=1;
		b[0]=i/1000; //千位 
		b[1]=i/100%10; //百位 
		b[2]=i/10%10;//十位 
		b[3]=i%10; //个位 
		if(b[0]!=b[1]&&b[0]!=b[2]&&b[0]!=b[3]){ //判断有几个不一样的数 
			k++;
		}
		if(b[1]!=b[2]&&b[1]!=b[3]){
			k++;
		}
		if(b[2]!=b[3]){
			k++;
		}
		if(k==n){
			break; //满足需求则跳出循环 
		}
		
	}
	printf("%d %04d",i-y,i); //按要求输出 
}
