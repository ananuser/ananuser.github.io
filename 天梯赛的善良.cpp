//#include <stdio.h>
//int main(){
//	int n,a[20000],ma=0,mi=0,i,max=0,min=2000000;
//	scanf("%d",&n);
//	for (i=0;i<n;i++){
//		scanf("%d",&a[i]);
//		if(a[i]>max){
//			max=a[i];
//		}
//		if(a[i]<min){
//			min=a[i];
//		}
//	}
//	for(i=0;i<n;i++){
//		if(a[i]==max){
//			ma++;
//		}
//		if(a[i]==min){
//			mi++;
//		}
//	}
//	printf("%d %d\n",min,mi);
//	printf("%d %d\n",max,ma);
//}

#include <stdio.h>
int main(){
	int n,a,i,max=0,min=100000;
	int x[20000]={0};
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&a);
		if(a>max){
			max=a;
		}
		if(a<min){
			min=a;
		}
		x[a]++;
	}
	printf("%d %d\n%d %d",min,x[min],max,x[max]);
}
