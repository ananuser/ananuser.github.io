#include <stdio.h>
int main(){
	int i,n,a,b;
	char x[5];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d %d",&x,&a,&b);
		if((a>20 || a<15) || (b>70 || b<50)){
			printf("%s\n",x);
		}
	}
} 
