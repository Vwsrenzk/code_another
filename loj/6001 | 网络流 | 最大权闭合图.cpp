#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 210
#define INF 1000000000
using namespace std;
int n,m,num=1,head[maxn],sum,dis[maxn],S,T;
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
			if(!delta)dis[to]=0;
			e[i].v-=delta;
			e[i^1].v+=delta;
			rest-=delta;
		}
	}
	return flow-rest;
}
void dfs(int x){
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(e[i].v&&!flag[to]){
			flag[to]=1;
			dfs(to);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	S=0,T=n+m+1;
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);sum+=x;
		Insert(S,i,x);
		char ch=getchar();int j=0;
		while(ch!='\r'){
			if(ch<='9'&&ch>='0')j=j*10+ch-'0';
			else if(j)Insert(i,j+n,INF),j=0;
			ch=getchar();
		}
		Insert(i,j+n,INF);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		Insert(i+n,T,x);
	}
	while(bfs())
		sum-=dinic(S,INF);
	dfs(S);
	for(int i=1;i<=n;i++)
		if(flag[i])printf("%d ",i);
	puts("");
	for(int i=n+1;i<=n+m;i++)
		if(flag[i])printf("%d ",i-n);
	puts("");
	printf("%d",sum);
	return 0;
}
