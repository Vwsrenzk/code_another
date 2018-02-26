#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 110
#define INF 100000000
using namespace std;
int n,m,head[maxn],num=1,dis[maxn],ans,S,T;
struct node{int to,pre,v;}e[maxn*maxn*2];
void Insert(int from,int to,int v){
	e[++num].to=to;e[num].v=v;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].pre=head[to];head[to]=num;
}
bool bfs(){
	queue<int>q;
	for(int i=1;i<=T;i++)dis[i]=INF;
	q.push(S);dis[S]=0;
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]>dis[now]+1&&e[i].v>0){
				dis[to]=dis[now]+1;
				if(to==T)return 1;
				q.push(to);
			}
		}
	}
	return dis[T]!=INF;
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
	scanf("%d%d",&n,&m);
	S=0;T=n+1;
	for(int i=1;i<=m;i++)Insert(S,i,1);
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF)Insert(x,y,1);
	for(int i=m+1;i<=n;i++)Insert(i,T,1);
	while(bfs())ans+=dinic(S,INF);
	printf("%d",ans);
	return 0;
}
