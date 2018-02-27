#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 610
#define INF 1000000000
using namespace std;
int dis[maxn],head[maxn],num=1,n,m,S,T,ans;
struct node{int to,pre,v;}e[maxn*maxn*2];
void Insert(int from,int to,int v){
	e[++num].to=to;e[num].v=v;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].pre=head[to];head[to]=num;
}
bool bfs(){
	for(int i=S;i<=T;i++)dis[i]=INF;
	queue<int>q;
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
	S=0;T=n+m+1;int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);ans+=x;
		Insert(S,i,x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		Insert(i+n,T,x);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			Insert(i,j+n,1);
	while(bfs())
		ans-=dinic(S,INF);
	if(ans!=0){puts("0");return 0;}
	puts("1");
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=e[j].pre){
			int to=e[j].to;
			if(e[j].v==0&&(to-n>0)){
				printf("%d ",to-n);
			}
		}
		puts("");
	}
	return 0;
}
