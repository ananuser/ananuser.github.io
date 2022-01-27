#include<stdio.h>
int main(){
	int c,n,count;
	scanf("%d",&n);
	char s1[15]="ChuiZi",s2[15]="JianDao",s3[15]="Bu";
	char a[15];
	while(scanf("%s",a)!=EOF){
		count++;
		if(a[0]=='C'){
			if(count>n){
				count=0;
				printf("%s\n",a);
			}else{
				printf("%s\n",s3); 
			}
		}else if(a[0]=='J')	{
			if(count>n){
				count=0;
				printf("%s\n",a);
			}else{
				printf("%s\n",s1); 
			}
		}else if(a[0]=='B'){
			if(count>n){
				count=0;
				printf("%s\n",a);
			}else{
				printf("%s\n",s2);
			}
		}else{
			break;
		}	
	}
}
