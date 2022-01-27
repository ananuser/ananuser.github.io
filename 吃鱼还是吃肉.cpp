#include <stdio.h>
int main(){
	int i,n,x,s,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&x,&s,&t);
		if(x==0){
			if(s<129){
				printf("duo chi yu! ");
			}else if(s==129){
				printf("wan mei! ");
			}else{
				printf("ni li hai! ");
			}
			if(t<25){
				printf("duo chi rou!\n");
			}else if(t==25){
				printf("wan mei!\n");
			}else{
				printf("shao chi rou!\n");
			}
		}
		if(x==1){
			if(s<130){
				printf("duo chi yu! ");
			}else if(s==130){
				printf("wan mei! ");
			}else{
				printf("ni li hai! ");
			}
			if(t<27){
				printf("duo chi rou!\n");
			}else if(t==27){
				printf("wan mei!\n");
			}else{
				printf("shao chi rou!\n");
			}
		}
	}
}
