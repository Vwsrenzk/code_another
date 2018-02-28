#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 210
#define INF 1000000000
using namespace std;
int n,S,T,num=1,head[maxn],dis[maxn],ans;
bool vis[maxn];
struct node{int to,pre,v,cost;}e[maxn*maxn*2];
void Insert(int from,int to,int v,int cost){
	e[++num].to=to;e[num].v=v;e[num].cost=cost;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].cost=-cost;e[num].pre=head[to];head[to]=num;
}
bool spfa(){
	queue<int>q;
	for(int i=S;i<=T;i++)dis[i]=INF,vis[i]=0;
	dis[S]=0;vis[S]=1;q.push(S);
	while(!q.empty()){
		int now=q.front();q.pop();vis[now]=0;
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]>dis[now]+e[i].cost&&e[i].v>0){
				dis[to]=dis[now]+e[i].cost;
				if(!vis[to]){vis[to]=1;q.push(to);}
			}
		}
	}
	return dis[T]<INF;
}
bool spfa2(){
	queue<int>q;
	for(int i=S;i<=T;i++)dis[i]=-INF,vis[i]=0;
	dis[S]=0;vis[S]=1;q.push(S);
	while(!q.empty()){
		int now=q.front();q.pop();vis[now]=0;
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]<dis[now]+e[i].cost&&e[i].v>0){
				dis[to]=dis[now]+e[i].cost;
				if(!vis[to]){vis[to]=1;q.push(to);}
			}
		}
	}
	return dis[T]>0;
}
int dinic(int x,int flow){
	vis[x]=1;
	if(x==T||!flow)return flow;
	int rest=flow;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(!vis[to]&&dis[to]==dis[x]+e[i].cost&&e[i].v>0){
			int delta=dinic(to,min(rest,e[i].v));
			e[i].v-=delta;
			e[i^1].v+=delta;
			rest-=delta;
			ans+=delta*e[i].cost;
		}
	}
	return flow-rest;
}
int main(){
	scanf("%d",&n);
	int x;S=0;T=2*n+1;
	for(int i=1;i<=n;i++){
		Insert(S,i,1,0);Insert(i+n,T,1,0);
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			Insert(i,j+n,1,x);
		}
	}
	while(spfa()){
		memset(vis,0,sizeof(vis));
		dinic(S,INF);
	}
	printf("%d\n",ans);
	for(int i=2;i<=num;i++){
		if((i^1)>i){
			e[i].v+=e[i^1].v;
			e[i^1].v=0;
		}
	}
	ans=0;
	while(spfa2()){
		memset(vis,0,sizeof(vis));
		dinic(S,INF);
	}
	printf("%d",ans);
	return 0;
}
