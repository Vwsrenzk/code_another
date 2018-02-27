#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1500
#define INF 1000000000
using namespace std;
int head[maxn],num=1,S,T,n,m,dis[maxn],sum;
struct node{int to,pre,v;}e[30*1010*2];
void Insert(int from,int to,int v){
	e[++num].to=to;e[num].v=v;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].pre=head[to];head[to]=num;
}
bool bfs(){
	queue<int>q;
	memset(dis,-1,sizeof(dis));
	dis[S]=0;q.push(S);
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]==-1&&e[i].v>0){
				dis[to]=dis[now]+1;
				if(to==T)return 1;
				q.push(to);
			}
		}
	}
	return dis[T]!=-1;
}
int dinic(int x,int flow){
	if(x==T)return flow;
	int rest=flow;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(dis[to]==dis[x]+1&&e[i].v>0){
			int delta=dinic(to,min(rest,e[i].v));
			e[i].v-=delta;
			e[i^1].v+=delta;
			rest-=delta;
		}
	}
	return flow-rest;
}
int main(){
	scanf("%d%d",&n,&m);//类型数，试题数 
	S=0;T=n+m+1;int x,y;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);sum+=x;
		Insert(i+m,T,x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			scanf("%d",&y);Insert(i,y+m,1);
		}
	}
	for(int i=1;i<=m;i++)Insert(S,i,1);
	while(bfs())
		sum-=dinic(S,INF);
	if(sum!=0){puts("No Solution!");return 0;}
	for(int i=1;i<=n;i++){
		printf("%d:",i);
		for(int j=head[i+m];j;j=e[j].pre){
			int to=e[j].to;
			if(e[j].v!=0&&to<=m&&to>=1){
				printf(" %d",to);
			}
		}
		puts("");
	}
	return 0;
}
