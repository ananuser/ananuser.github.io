#include <stdio.h>
#include <string.h>
int main(){
	char str[105];
	int n,i,j,k,len,flag1=0,flag2=0,count=0,t=0;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		flag1=0,flag2=0,count=0,t=0;
		gets(str);
		len=strlen(str);
		for(j=0;j<len;j++){
			if(str[j]==','){
				if(str[j-3]=='o'&&str[j-2]=='n'&&str[j-1]=='g'){
					flag1=1;
				}
			}
			if(str[j]=='.'){
				if(str[j-3]=='o'&&str[j-2]=='n'&&str[j-1]=='g'){
					flag2=1;
				}
			}
		}
		if(flag1==1&&flag2==1){
			for(k=len-1;k>=0;k--){
				if(str[k]==' '){
					count++;
				}
				if(count==3){
					break;
				}
				t++;
			}
			for(k=0;k<len-t;k++){
				printf("%c",str[k]);
			}
			printf("qiao ben zhong.\n");
		}else{
			printf("Skipped\n");
		}
	}
}
