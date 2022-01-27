#include <stdio.h>
int main(){
	float f,t,s;
	scanf("%f %f",&t,&s);
	f=t/(s*s);
	if(f>25){
		printf("%.1f\nPANG",f);
	}else{
		printf("%.1f\nHai Xing",f);
	}
}
