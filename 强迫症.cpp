#include <stdio.h>
#include <string.h>
int main(){
	char a[6];
	int n;
	scanf("%s",a);
	int len=strlen(a);
	if(len==6){
		printf("%c%c%c%c-%c%c",a[0],a[1],a[2],a[3],a[4],a[5]);
	}else{
		n=(a[0]-'0')*10+(a[1]-'0')
		n=n<22?20:19;
		printf("%d%c%c-%c%c",n,a[0],a[1],a[2],a[3]);
	}
}
