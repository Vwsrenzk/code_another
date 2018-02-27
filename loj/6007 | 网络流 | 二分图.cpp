#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1000
#define INF 1000000000
using namespace std;
int n,m,head[maxn],num=1,S,T,dis[maxn],ans;
struct node{int to,pre,v;}e[maxn*maxn*2];
void Insert(int from,int to,int v){
	e[++num].to=to;e[num].v=v;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].pre=head[to];head[to]=num;
}
int mk(int x,int y){return (x-1)*m+y;}
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
	scanf("%d%d",&n,&m);
	S=0;T=n*m+1;int x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&x);ans+=x;
			if(i+j&1)Insert(mk(i,j),T,x);
			else Insert(S,mk(i,j),x);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(i+j&1)continue;
			if(i-1>=1)Insert(mk(i,j),mk(i-1,j),INF);
			if(i+1<=n)Insert(mk(i,j),mk(i+1,j),INF);
			if(j-1>=1)Insert(mk(i,j),mk(i,j-1),INF);
			if(j+1<=m)Insert(mk(i,j),mk(i,j+1),INF);
		}
	while(bfs())ans-=dinic(S,INF);
	printf("%d",ans);
	return 0;
}
