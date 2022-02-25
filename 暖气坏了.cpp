#include <stdio.h>
int main(){
	int i,s=0,a[10001],n,m;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++){
		if(a[i]-a[i-1]<=m){
			s+=a[i]-a[i-1];
		}else{
			s+=m;
		}
	}
	s+=m;
	printf("%d",s);
}
