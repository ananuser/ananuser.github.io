#include <stdio.h>
#include <string.h>
int main(){
	char str[1001];
	int count=0,i,j;
	gets(str);
	for(i=0;i<=strlen(str);i++){
		if(str[i]=='6'){
			count++;
		}else{
			if(count>9){
				printf("27");
			}else if(count>3){
				printf("9");
			}else{
				for(j=0;j<count;j++){
					printf("6");
				}
			}
			printf("%c",str[i]);
			count=0; 
		}
	}
} 
