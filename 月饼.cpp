#include <stdio.h>
#include <stdlib.h>
#define max 1005
typedef struct{
	double num;
	double sum;
	double sale;
}node;
node a[max];
int n,i,j;
double d,pro=0;
int main(){
	scanf("%d %lf",&n,&d);
	for(i=0;i<n;i++){
		scanf("%lf",&a[i].num);
	}
	for(i=0;i<n;i++){
		scanf("%lf",&a[i].sum);
		a[i].sale=(double)a[i].sum/a[i].num;
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].sale<a[j].sale){
				node t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n&&d>0;i++){
		if(d<=a[i].num){
			pro+=d*a[i].sale;
			d=0;
		}else{
			pro+=a[i].sum;
			d-=a[i].num;
		}
	}
	printf("%.2lf",pro);
}
