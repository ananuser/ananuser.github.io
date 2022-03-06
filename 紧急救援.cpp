#include <stdio.h>
void Dijkstra();
void Print(int t);
#define max 505
#define MAX 100000
const int INF=1e9+7;
int n,m,s,d;
int a,b,c;
int i,j;
int people[max],graph[max][max],dis[max],visit[max],num[MAX],cnt[MAX],way[MAX];
int main(){
	scanf("%d %d %d %d",&n,&m,&s,&d);
	for(i=0;i<n;i++){
		scanf("%d",&people[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				graph[i][j]=INF;
			}else{
				graph[i][j]=0;
			}
		}
	}
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		graph[a][b]=c;
		graph[b][a]=c;
	}
	Dijkstra();
	printf("%d %d\n",cnt[d],num[d]);
	Print(d);
}
void Dijkstra(){
	dis[s]=0;
	num[s]=people[s];
	cnt[s]=1;
	way[s]=s;
	for(i=0;i<n;i++){
		dis[i]=graph[s][i];
	}
	for(i=0;i<n;i++){
		int min_dist=INF;
		int mid=-1;
		for(j=0;j<n;j++){
			if(visit[j]==0&&min_dist>dis[j]){
				min_dist=dis[j];
				mid=j;
			}
		}
		if(mid==-1){
			break;
		}
		visit[mid]=1;
		for(j=0;j<n;j++){
			if(visit[j]==0&&dis[j]>dis[mid]+graph[mid][j]){
				dis[j]=dis[mid]+graph[mid][j];
				cnt[j]=cnt[mid];
				num[j]=num[mid]+people[j];
				way[j]=mid;
			}else if(visit[j]==0&&dis[j]==dis[mid]+graph[mid][j]){
				cnt[j]+=cnt[mid];
				if(num[j]<num[mid]+people[j]){
					num[j]=num[mid]+people[j];
					way[j]=mid;
				}
			}
		}
	}
}
void Print(int t){
	if(t==s){
		printf("%d",s);
		return;
	}
	Print(way[t]);
	printf(" %d",t);
}
