#include <stdio.h>
int main(){
	int L,N,C,T,VR,VT1,VT2;
	int p[110];
	int k=0;
	double dp[1005];
	double tuzi,x;
	while(scanf("%d",&L)!=EOF){ //�õ��˶������� 
	    scanf("%d %d %d",&N,&C,&T);  //������վ�������������Ժ�����ʻ�ľ����Լ�ÿ�γ������Ҫ��ʱ�� 
	    scanf("%d %d %d",&VR,&VT1,&VT2); //�������ܲ����ٶȣ��ڹ꿪�綯�����ٶȣ��ڹ�ŵŵ綯�����ٶ� 
		for(int i=1;i<=N;i++){
			scanf("%d",&p[i]); //����������վ�����ܵ�ľ��� 
		}
		p[N+1]=L; //�յ���վ�����������ΪL 
		p[0]=0; //��� 
		tuzi=1.0*L/VR;  //��������ȫ������Ҫ��ʱ�� 
		dp[0]=0;  //��ʼʱ��Ϊ0 
		for(int i=1;i<=N+1;i++){  
			double min=10000000000; 
			for(int j=0;j<i;j++){
				int t=p[i]-p[j]; //�����վ֮��ľ��� 
				if(t>C){ //��������ﳵ���� 
					x=(1.0*C/VT1+1.0*(t-C)/VT2); //�ﳵʱ����Ͻŵ�ʱ�� 
				}else{ //���С�� 
					x=1.0*t/VT1; //��������ﳵ�ٶ������ʱ�� 
				}  //��þ�������ʱ�� 
				x+=dp[j]; // ��ÿһ�μ���ʱ����� 
				if(j){ //������վʱ��� 
					x+=T;  //���ӳ��ʱ�� 
				}
				if(min>x)  //ȡ��Сֵ 
					min=x;
			}
			dp[i]=min;  //��¼ÿ�����ʱ�� 
		}
		if(tuzi>dp[N+1]){  //��������� 
			printf("What a pity rabbit!\n");
		}else  //����ڹ��� 
			printf("Good job,rabbit!\n");
	}
}
