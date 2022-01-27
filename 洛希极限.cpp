#include <stdio.h>
int main(){
	float a,b,d;
	int c;
	scanf("%f %d %f",&a,&c,&b);
	if(c==0){
		d=a*2.455;
		printf("%.2f T_T",d);
	}else{
		d=a*1.26;
		printf("%.2f ^_^",d);
	}
}
