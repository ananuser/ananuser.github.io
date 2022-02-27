#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*e1,const void*e2){
	return *(int*)e2-*(int*)e1;
}
int main(){
	char str[12];
	scanf("%s",str);
	int arr[12]={0},index[12],flag[12]={0};
	int i,j,k,count=0;
	for(i=0;i<strlen(str);i++){
		if(flag[str[i]-'0']==0)
			arr[count++]=str[i]-'0';
		flag[str[i]-'0']=1;
		index[i]=str[i]-'0';
	}
	int sz=sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),cmp);
	printf("int[] arr = new int[]{");
	printf("%d",arr[0]);
	for(i=1;i<count;i++){
		printf(",");
		printf("%d",arr[i]);
	}
	printf("};\n");
	printf("int[] index = new int[]{");
	for(j=0;j<count;j++){
		if(index[0]==arr[j]){
			printf("%d",j);
		}
	}
	for(i=1;i<strlen(str);i++){
		for(j=0;j<count;j++){
			if(index[i]==arr[j]){
				printf(",%d",j);
			}
		}
	}
	printf("};");
}
