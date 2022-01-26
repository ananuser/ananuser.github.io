#include <stdio.h>
int main(){
	int m,n,i,j;
	scanf("%d",&n);
	long long int  a[1000];
	int b[1000],c[1000],x[1000];
	for(i=0;i<n;i++){
		scanf("%lld %d %d",&a[i],&b[i],&c[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&x[i]);
		for(j=0;j<n;j++){
			if(x[i]==b[j]){
				printf("%lld %d\n",a[j],c[j]);
			}
		}
	}
	
}
