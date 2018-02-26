/*要用当前弧优化*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define maxn 3210
#define INF 1000000000
using namespace std;
int head[maxn],cur[maxn],num=1,dis[maxn],flow,ans,S,T;
struct node{int to,pre,v;}e[maxn*maxn];
void Insert(int from,int to,int v){
	e[++num].to=to;e[num].v=v;e[num].pre=head[from];head[from]=num;
	e[++num].to=from;e[num].v=0;e[num].pre=head[to];head[to]=num;
}
bool bfs(){
	queue<int>q;
	for(int i=S;i<=T;i++)cur[i]=head[i],dis[i]=INF;
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
int dinic(int x,int fl){
	if(x==T)return fl;
	int rest=fl;
	for(int &i=cur[x];i;i=e[i].pre){
		int to=e[i].to;
		if(dis[to]==dis[x]+1&&e[i].v>0){
			int delta=dinic(to,min(e[i].v,rest));
			e[i].v-=delta;
			e[i^1].v+=delta;
			rest-=delta;
		}
	}
	if(rest==fl)dis[x]=-1;
	return fl-rest;
}
bool check(int n){
	memset(head,0,sizeof(head));num=1;
	memset(e,0,sizeof(e));
	S=0;T=n*2+1;
	for(int i=1;i<=n;i++)Insert(S,i,1);
	for(int i=n+1;i<=n*2;i++)Insert(i,T,1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int t=sqrt(i+j);
			if(t*t==i+j)Insert(i,j+n,1);
		}
	int maxflow=0;
	while(bfs())maxflow+=dinic(S,INF);
	if(flow+maxflow<n)return false;
	return true;
}
int main(){
	scanf("%d",&flow);
	if(!flow){puts("0");return 0;}
	int l=1,r=1600;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
}
