//#include <stdio.h>
//int main(){
//	int n,i=1,j=1;
//	char a;
//	scanf("%d %c",&n,&a);
//	int sum,num=1;
//	while(i<=n){
//		j+=2;
//		i+=j*2; 
//		num+=2; 
//	}
//	i-=j*2; //总个数 
//	num-=2; //行数，由于上面while循环中会多算一次要减掉 
//	sum=n-i; //剩余个数 
//	for(j=0;j<num/2+1;j++){
//		for(i=0;i<j;i++){
//			printf(" ");
//		}
//		for(i=0;i<num-j*2;i++){
//			printf("%c",a);
//		}
//		printf("\n");
//	} 
//	for(j=0;j<num/2;j++){
//		for(i=0;i<num/2-1-j;i++){
//			printf(" ");
//		}
//		for(i=0;i<j*2+3;i++){
//			printf("%c",a);
//		}
//		printf("\n");
//	}
//	printf("%d",sum);
//	
//}
#include <stdio.h>
int main()
{ 	int i,n,N,j,k,sum,s;
    printf("请输入N的值：");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    { 	sum=2*i*i+4*i+1;
       	if(sum>=N) break;
 }
if(sum>N) {i-=1;sum=2*i*i+4*i+1;s=N-sum;}
   	else s=0;k=i;
   	for (j=1;j<=i;j++)
     { 	for(n=1;n<=j-1;n++)
       {	printf (" ");} 
    for(n=1;n<=2*k+1;n++)
     { printf ("*");}
     printf("\n");k--;
  }
  for(n=1;n<=j-1;n++)
       {printf (" ");} 
    printf("*\n");k=i;
    for (j=1;j<=i;j++)
      {for (n=k-1;n>=1;n--)
           {printf(" ");}k--;
       for (n=1;n<=2*j+1;n++)
         { printf("*");}printf("\n");
   } 
   printf("\n%d",s);
 
}
