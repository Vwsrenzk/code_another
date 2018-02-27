#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 10010
#define INF 1000000000
using namespace std;
int day,m,S,T,p,f,n,s;
int r[maxn],head[maxn],num=1,dis[maxn],ans;
bool vis[maxn];
struct node{int to,pre,v,cost;}e[maxn*20];
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
				if(!vis[to])vis[to]=1,q.push(to);
			}
		}
	}
	return dis[T]!=INF;
}
int dinic(int x,int flow){
	vis[x]=1;
	if(x==T||!flow)return flow;
	int rest=flow;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(!vis[to]&&e[i].v&&dis[to]==dis[x]+e[i].cost){
			int delta=dinic(to,min(rest,e[i].v));
			e[i].v-=delta;
			e[i^1].v+=delta;
			rest-=delta;
			ans+=e[i].cost*delta;
		}
	}
	return flow-rest;
}
int cost_flow(){
	while(spfa()){
		memset(vis,0,sizeof(vis));
		dinic(S,INF);
	}
}
int main(){
	scanf("%d%d%d%d%d%d",&day,&p,&m,&f,&n,&s);
	S=0;T=day*2+1;
	for(int i=1;i<=day;i++)scanf("%d",&r[i]);
	for(int i=1;i<=day;i++){
		Insert(S,i,r[i],0);
		Insert(i+day,T,r[i],0);
		Insert(S,i+day,INF,p);//买新的 
		Insert(i+day,i,INF,0);//用旧 
		if(i+1<=day)Insert(i,i+1,INF,0);//留到下一天 
		if(i+m<=day)Insert(i,i+m+day,INF,f);//快洗 
		if(i+n<=day)Insert(i,i+n+day,INF,s);//慢洗 
	}
	cost_flow();
	cout<<ans;
	return 0;
}
