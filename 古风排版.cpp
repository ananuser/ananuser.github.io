#include<stdio.h>
#include<string.h>
int main(){
	int N,len,n,i,j,t;
	char str[1005],a[100][100];
	scanf("%d",&N);
	getchar();
	gets(str);
	len=strlen(str);
	n=len/N;
	if(len%N!=0){
		n++;
	}
	for(j=n-1;j>=0;j--){
		for(i=0;i<N;i++){
			if(str[t]!='\0'){
				a[i][j]=str[t];
				t++;
			}else{
				a[i][j]=' ';
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<n;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}
