#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1010
#define INF 1000000000
using namespace std;
int f[510],n,a[510],S,T,dis[maxn],ml,head[maxn],num=1;
struct node{int to,pre,v;}e[maxn*maxn*2];
void Insert(int from,int to,int v){
	e[++num].to=to;e[num].v=v;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].pre=head[to];head[to]=num;
}
void build(){
	for(int i=1;i<=n;i++){
		if(f[i]==1)Insert(S,i,1);
		Insert(i,i+n,1);
		if(f[i]==ml)Insert(i+n,T,1);
		for(int j=1;j<i;j++)
			if(a[j]<=a[i]&&f[j]+1==f[i])Insert(j+n,i,1);
	}
}
void build2(){
	memset(head,0,sizeof(head));num=1;
	for(int i=1;i<=n;i++){
		if(i==1||i==n){
			if(f[i]==1)Insert(S,i,INF);
			Insert(i,i+n,INF);
			if(f[i]==ml)Insert(i+n,T,INF);
		}
		else {
			if(f[i]==1)Insert(S,i,1);
			Insert(i,i+n,1);
			if(f[i]==ml)Insert(i+n,T,1);
		}
		for(int j=1;j<i;j++){
			if(a[j]<=a[i]&&f[j]+1==f[i])Insert(j+n,i,1);
		}
	}
}
bool bfs(){
	queue<int>q;
	for(int i=S;i<=T;i++)dis[i]=INF;
	dis[S]=0;q.push(S);
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]>dis[now]+1&&e[i].v>0){
				dis[to]=dis[now]+1;
				if(now==T)return 1;
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
	scanf("%d",&n);
	S=0;T=n*2+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=i;j>=1;j--){
			if(a[j]<=a[i])f[i]=max(f[i],f[j]+1);
			ml=max(ml,f[i]);
		}
	printf("%d\n",ml);
	if(ml==1){printf("%d\n%d",n,n);return 0;}
	build();
	int ans=0;
	while(bfs())ans+=dinic(S,INF);
	printf("%d\n",ans);
	build2();
	ans=0;
	while(bfs())ans+=dinic(S,INF);
	printf("%d\n",ans);
	return 0;
}
