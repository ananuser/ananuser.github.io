#include <stdio.h>
int max(int a,int b){
	int t;
	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}
	return a;  //辗转相除法求最大公因式 
}
int main(){
	int n;
	scanf("%d",&n);
	int a,b,a1,b1,i,x,t;
	scanf("%d/%d",&a,&b);
	for(i=1;i<n;i++){
		scanf("%d/%d",&a1,&b1);
		a=a*b1+b*a1;
		b=b*b1;
		t=max(a,b);
		a=a/t;
		b=b/t;
	}
	if(b==1){
		printf("%d",a);
	}else if(a>b){
		t=a%b;
		x=a/b;//整数 
		printf("%d %d/%d",x,t,b);
	}else{
		printf("%d/%d",a,b);
	}
}
