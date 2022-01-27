#include<stdio.h>
int main(){
	int i,n;
	float s,x;
	char a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		getchar();
		scanf("%c %f",&a,&x);
		if(a=='M'){
			s=x/1.09;
			printf("%.2f\n",s);
		}else{
			s=x*1.09;
			printf("%.2f\n",s);
		}
		
	}
	
}
