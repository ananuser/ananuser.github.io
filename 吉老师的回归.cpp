#include <string.h>
#include <stdio.h>
int main(){
	int i,n,m;
	char s[501],str[501]="Wo AK le";
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<n;i++){
		gets(s);
		if(strstr(s,"qiandao")==NULL && strstr(s,"easy")==NULL){
			m--;
		}
		if(m<0){
			strcpy(str,s);
			break; 
		}
	}
	printf("%s",str);
}
