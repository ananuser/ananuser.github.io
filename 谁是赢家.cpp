#include<stdio.h>
int main(){
	int p,i,j,k,pa,pb;
	scanf("%d %d",&pa,&pb);
	scanf("%d %d %d",&i,&j,&k);
	p=i+j+k;
	if(p==3){
		printf("The winner is b: %d + %d",pb,p);
	}else if(p==0){
		printf("The winner is a: %d + %d",pa,3-p);
	}else if(pa>pb){
		printf("The winner is a: %d + %d",pa,3-p);
	}else{
		printf("The winner is b: %d + %d",pb,p);
	}
}
