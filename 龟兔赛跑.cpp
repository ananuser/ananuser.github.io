#include <stdio.h>
int main(){
	int L,N,C,T,VR,VT1,VT2;
	int p[110];
	int k=0;
	double dp[1005];
	double tuzi,x;
	while(scanf("%d",&L)!=EOF){ //用到了多组输入 
	    scanf("%d %d %d",&N,&C,&T);  //输入充电站个数，冲满电以后能行驶的距离以及每次充电所需要的时间 
	    scanf("%d %d %d",&VR,&VT1,&VT2); //输入子跑步的速度，乌龟开电动车的速度，乌龟脚蹬电动车的速度 
		for(int i=1;i<=N;i++){
			scanf("%d",&p[i]); //输入各个充电站离起跑点的距离 
		}
		p[N+1]=L; //终点充电站化，距离起点为L 
		p[0]=0; //起点 
		tuzi=1.0*L/VR;  //兔子跑完全程所需要的时间 
		dp[0]=0;  //初始时间为0 
		for(int i=1;i<=N+1;i++){  
			double min=10000000000; 
			for(int j=0;j<i;j++){
				int t=p[i]-p[j]; //两充电站之间的距离 
				if(t>C){ //如果大于骑车距离 
					x=(1.0*C/VT1+1.0*(t-C)/VT2); //骑车时间加上脚蹬时间 
				}else{ //如果小于 
					x=1.0*t/VT1; //距离除以骑车速度算出来时间 
				}  //获得经过间距的时间 
				x+=dp[j]; // 将每一段间距的时间相加 
				if(j){ //到达充电站时充电 
					x+=T;  //增加充电时间 
				}
				if(min>x)  //取最小值 
					min=x;
			}
			dp[i]=min;  //记录每次最短时间 
		}
		if(tuzi>dp[N+1]){  //如果兔子慢 
			printf("What a pity rabbit!\n");
		}else  //如果乌龟慢 
			printf("Good job,rabbit!\n");
	}
}
