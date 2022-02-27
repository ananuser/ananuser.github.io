#include <stdio.h>
int main(){
	int n,i,j,flag=0;
	char c;
	scanf("%c %d",&c,&n);
	getchar();
	char str[105][105];
	for(i=0;i<n;i++){
		gets(str[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(str[i][j]!=str[n-i-1][n-j-1]){
				flag=1;
				break;
			}
		}
		if(flag){
			break;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(str[i][j]!=' '){
				str[i][j]=c;
			}
		}
	}
	if(flag){
		for(i=n-1;i>=0;i--){
			for(j=n-1;j>=0;j--){
				printf("%c",str[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("bu yong dao le");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%c",str[i][j]);
			}
			printf("\n");
		}
	}
}
