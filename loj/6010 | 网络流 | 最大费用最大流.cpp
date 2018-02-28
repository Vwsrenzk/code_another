#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 1000000000
#define maxn 1010
using namespace std;
int S,T,num=1,n,m;
int dis[maxn],head[maxn],a[maxn][maxn],sz,ans;
bool vis[maxn];
struct node{int to,pre,v,cost;}e[maxn*maxn*2];
void Insert(int from,int to,int v,int cost){
	e[++num].to=to;e[num].v=v;e[num].cost=cost;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].cost=-cost;e[num].pre=head[to];head[to]=num;
}
bool spfa(){
	memset(vis,0,sizeof(vis));
	memset(dis,-0x3f,sizeof(dis));
	queue<int>q;q.push(S);dis[S]=0;vis[S]=1;
	while(!q.empty()){
		int now=q.front();q.pop();vis[now]=0;
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]<dis[now]+e[i].cost&&e[i].v>0){
				dis[to]=dis[now]+e[i].cost;
				if(!vis[to])vis[to]=1,q.push(to);
			}
		}
	}
	return dis[T]>-INF;
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
			ans+=e[i].cost*delta;
		}
	}
	return flow-rest;
}
void cost_flow(){
	while(spfa()){
		memset(vis,0,sizeof(vis));
		dinic(S,INF);
	}
}
void work1(){
	memset(head,0,sizeof(head));num=1;
	memset(e,0,sizeof(e));
	int cnt=m,id=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			id++;
			if(i==1)Insert(S,id,1,0);
			Insert(id,id+sz,1,a[i][j]);
			if(i!=n){
				Insert(id+sz,id+cnt,1,0);
				Insert(id+sz,id+cnt+1,1,0);
			}
			if(i==n){
				Insert(id+sz,T,1,0);
			}
		}
		cnt++;
	}
	ans=0;
	cost_flow();
	printf("%d\n",ans);
}
void work2(){
	memset(head,0,sizeof(head));num=1;
	memset(e,0,sizeof(e));
	int cnt=m,id=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			id++;
			if(i==1)Insert(S,id,1,0);
			if(i!=n){
				Insert(id,id+cnt,1,a[i][j]);
				Insert(id,id+cnt+1,1,a[i][j]);
			}
			if(i==n){
				Insert(id,T,INF,a[i][j]);
			}
		}
		cnt++;
	}
	ans=0;
	cost_flow();
	printf("%d\n",ans);
}
void work3(){
	memset(head,0,sizeof(head));num=1;
	memset(e,0,sizeof(e));
	int cnt=m,id=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			id++;
			if(i==1)Insert(S,id,1,0);
			Insert(id,id+sz,INF,a[i][j]);
			if(i!=n){
				Insert(id+sz,id+cnt,INF,0);
				Insert(id+sz,id+cnt+1,INF,0);
			}
			if(i==n){
				Insert(id+sz,T,INF,0);
			}
		}
		cnt++;
	}
	ans=0;
	cost_flow();
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&m,&n);
	int cnt=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++)
			scanf("%d",&a[i][j]),sz++;
		cnt++;
	}
	S=0;T=sz*2+1;
	work1();
	work2();
	work3();
	return 0;
}
