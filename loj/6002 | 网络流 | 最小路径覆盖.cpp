#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 510
#define INF 1000000000
using namespace std;
int head[maxn],num=1,n,m,dis[maxn],S,T,nxt[maxn];
bool flag[maxn];
struct node{int to,pre,v;}e[maxn*maxn*2];
void Insert(int from,int to,int v){
	e[++num].to=to;e[num].v=v;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].pre=head[to];head[to]=num;
}
bool bfs(){
	queue<int>q;
	for(int i=1;i<=T;i++)dis[i]=INF;
	dis[S]=0;q.push(S);
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
			if(delta){
				nxt[x]=e[i].to;
				if(e[i].to-n>0)flag[e[i].to-n]=1;
			}
			e[i].v-=delta;
			e[i^1].v+=delta;
			rest-=delta;
		}
	}
	return flow-rest;
}
int main(){
	scanf("%d%d",&n,&m);
	S=0;T=2*n+1;
	for(int i=1;i<=n;i++)Insert(S,i,1);
	for(int i=n+1;i<=n*2;i++)Insert(i,T,1);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		Insert(x,y+n,1);
	}
	int ans=n;
	while(bfs())ans-=dinic(S,INF);
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			printf("%d ",i);
			int k=i;
			while(nxt[k]){
				printf("%d ",nxt[k]-n);
				k=nxt[k]-n;
			}
			puts("");
		}
	}
	printf("%d",ans);
	return 0;
}
