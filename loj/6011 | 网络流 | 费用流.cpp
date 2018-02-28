#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 1000000000
#define maxn 210
using namespace std;
int head[maxn],num=1,dis[maxn],S,T,n,m,ans,cur[maxn];
bool vis[maxn];
struct node{int to,pre,v,cost;}e[maxn*maxn*2];
void Insert(int from,int to,int v,int cost){
	e[++num].to=to;e[num].v=v;e[num].cost=cost;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].cost=-cost;e[num].pre=head[to];head[to]=num;
}
bool spfa1(){
	deque<int>q;
	for(int i=S;i<=T;i++)cur[i]=head[i],vis[i]=0,dis[i]=INF;
	dis[S]=0;vis[S]=1;q.push_back(S);
	while(!q.empty()){
		int now=q.front();q.pop_front();vis[now]=0;
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]>dis[now]+e[i].cost&&e[i].v>0){
				dis[to]=dis[now]+e[i].cost;
				if(!vis[to]){
					vis[to]=1;
					if(!q.empty()&&dis[to]<dis[q.front()])q.push_front(to);
                    else q.push_back(to);
				}
			}
		}
	}
	return dis[T]<INF;
}
bool spfa2(){
	deque<int>q;
	for(int i=S;i<=T;i++)cur[i]=head[i],vis[i]=0,dis[i]=-INF;
	dis[S]=0;vis[S]=1;q.push_back(S);
	while(!q.empty()){
		int now=q.front();q.pop_front();vis[now]=0;
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]<dis[now]+e[i].cost&&e[i].v>0){
				dis[to]=dis[now]+e[i].cost;
				if(!vis[to]){
					vis[to]=1;
					if(!q.empty()&&dis[to]>dis[q.front()])q.push_front(to);
                    else q.push_back(to);
				}
			}
		}
	}
	return dis[T]>0;
}
int dinic(int x,int flow){
	vis[x]=1;
	if(x==T||!flow)return flow;
	int rest=flow;
	for(int &i=cur[x];i;i=e[i].pre){
		int to=e[i].to;
		if(!vis[to]&&dis[to]==dis[x]+e[i].cost&&e[i].v>0){
			int delta=dinic(to,min(rest,e[i].v));
			e[i].v-=delta;
			e[i^1].v+=delta;
			rest-=delta;
			ans+=delta*e[i].cost;
		}
	}
	if(flow==rest)dis[x]=-1;
	return flow-rest;
}
int main(){
	scanf("%d%d",&n,&m);
	int x;S=0;T=n+m+1;
	for(int i=1;i<=n;i++){scanf("%d",&x);Insert(S,i,x,0);}
	for(int i=1;i<=m;i++){scanf("%d",&x);Insert(i+n,T,x,0);}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){scanf("%d",&x);Insert(i,j+n,INF,x);}
	while(spfa1()){
		memset(vis,0,sizeof(vis));
		dinic(S,INF);
	}
	printf("%d\n",ans);
	ans=0;
	for(int i=2;i<=num;i++){
		if((i^1)>(i)){
			e[i].v+=e[i^1].v;
			e[i^1].v=0;
		}
	}
	while(spfa2()){
		memset(vis,0,sizeof(vis));
		dinic(S,INF);
	}
	printf("%d",ans);
	return 0;
}
