#include <stdio.h>
#include <string.h>
int main(){
	char a[20],b[20];
	scanf("%s",a);
	gets(b);
	int len_a=strlen(a),len_b=strlen(b);
	int i,j,flaga=0,flagb=0,A=0,B=0,t=1;
	for(i=len_a-1;i>=0;i--){
		if(a[i]-'0'<0||a[i]-'9'>9){
			flaga=1;
			break;
		}
		A+=t*(a[i]-'0');
		t*=10;
	}
	if(A>1000||A<1){
		flaga=1;
	}
	t=1;
	for(j=len_b-1;j>=1;j--){
		if(b[j]-'0'<0||b[j]-'9'>9){
			flagb=1;
			break;
		}
		B+=t*(b[j]-'0');
		t*=10;
	}
	if(B>1000||B<1){
		flagb=1;
	}
	if(!flaga&&!flagb){
		printf("%d + %d = %d",A,B,A+B);
	}else if(!flaga){
		printf("%d + ? = ?",A);
	}else if(!flagb){
		printf("? + %d = ?",B);
	}else{
		printf("? + ? = ?");
	}
}
