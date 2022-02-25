#include <stdio.h>
int main(){
	int i,j,k,n,s=0;
	scanf("%d",&n);
	for(i=0;i*5<n;i++){
		for(j=0;j*3<n;j++){
			for(k=0;k<n;k+=3){
				if(i+j+k==n && i*5+j*3+k/3==n){
					printf("%d %d %d\n",i,j,k);
					s++;
				}
			}
		}
	}
	if(s==0){
		printf("No Answer.");
	}
}
