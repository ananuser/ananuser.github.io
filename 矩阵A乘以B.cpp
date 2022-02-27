#include <stdio.h>
int main(){
	int Ra,Ca,Rb,Cb,i,j,k,num;
	int a[1000][1000],b[1000][1000];
	scanf("%d %d",&Ra,&Ca);
	for(i=1;i<=Ra;i++){
		for(j=1;j<=Ca;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d",&Rb,&Cb);
	for(i=1;i<=Rb;i++){
		for(j=1;j<=Cb;j++){
			scanf("%d",&b[i][j]);
		}
	}
	if(Ca!=Rb){
		printf("Error: %d != %d",Ca,Rb);
	}else{
		printf("%d %d\n",Ra,Cb);
		for(i=1;i<=Ra;i++){
			for(j=1;j<=Cb;j++){
				num=0;
				for(k=1;k<=Ca;k++){
					num+=a[i][k]*b[k][j];
				}
				printf("%d",num);
				if(j!=Cb){
					printf(" ");
				}
			}
			printf("\n");
		}
	}
}
