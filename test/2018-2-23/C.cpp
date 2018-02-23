#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define N 100010
#define inf 1000000000
using namespace std;
int head[N],n,m,cnt=1;
struct node{int v,pre,f;}e[N*2];
//----------------------------------------
int a[N],son[N],fa[N],dfn[N],bl[N],top[N],dep[N],tot,mn[N*4];
void add(int u,int v,int f){
	e[++cnt].v=v;e[cnt].f=f;e[cnt].pre=head[u];head[u]=cnt;
	e[++cnt].v=u;e[cnt].f=f;e[cnt].pre=head[v];head[v]=cnt;
}
void dfs1(int u){
	son[u]=1;
	for(int i=head[u];i;i=e[i].pre){
		if(e[i].v==fa[u]) continue;
		fa[e[i].v]=u;
		dep[e[i].v]=dep[u]+1;
		a[e[i].v]=e[i].f;
		bl[i/2]=e[i].v;
		dfs1(e[i].v);
		son[u]+=son[e[i].v];
	}
}
void dfs2(int u,int chain){
	dfn[u]=++tot;top[u]=chain;int k=0;
	for(int i=head[u];i;i=e[i].pre)
		if(e[i].v!=fa[u]&&son[e[i].v]>son[k])
			k=e[i].v;
	if(!k) return;
	dfs2(k,chain);
	for(int i=head[u];i;i=e[i].pre)
		if(e[i].v!=fa[u]&&e[i].v!=k)
			dfs2(e[i].v,e[i].v);
}
void push_up(int k){
	mn[k]=min(mn[k*2],mn[k*2+1]);
}
void modify(int k,int l,int r,int pos,int x){
	if(l==r){
		mn[k]=x;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(k*2,l,mid,pos,x);
	else modify(k*2+1,mid+1,r,pos,x);
	push_up(k);
}
int query(int k,int l,int r,int x,int y){
	if(l>=x&&r<=y) return mn[k];
	int mid=l+r>>1,ans=inf;
	if(x<=mid) ans=min(ans,query(k*2,l,mid,x,y));
	if(y>mid) ans=min(ans,query(k*2+1,mid+1,r,x,y));
	return ans;
}
int query_min(int x,int y){
	if(x==y) return 0;
	int ans=inf;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=min(ans,query(1,1,n,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	ans=min(ans,query(1,1,n,dfn[x]+1,dfn[y]));
	return ans;
}
void work1(){
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	dfs1(1);dfs2(1,1);
	for(int i=1;i<=n;i++) modify(1,1,n,dfn[i],a[i]);
	int T,op,x,y;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&op,&x,&y);
		if(!op) printf("%d\n",query_min(x,y));
		else modify(1,1,n,dfn[bl[x]],y);
	}
}
//------------------------------------------
int dis[N];
struct Node{int u,v,w;}ee[N];
queue<int> q;
bool bfs(int S,int T){
	memset(dis,-1,sizeof(dis));
	dis[S]=0;q.push(S);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].pre)
			if(e[i].f&&dis[e[i].v]==-1){
				dis[e[i].v]=dis[u]+1;
				q.push(e[i].v);
			}
	}
	return dis[T]!=-1;
}
int dinic(int u,int f,int T){
	if(u==T) return f;
	int rest=f;
	for(int i=head[u];i;i=e[i].pre)
		if(e[i].f&&dis[e[i].v]==dis[u]+1){
			int t=dinic(e[i].v,min(rest,e[i].f),T);
			if(!t) dis[e[i].v]=-1;
			e[i].f-=t;rest-=t;e[i^1].f+=t;
		}
	return f-rest;
}
void work2(){
	for(int i=1;i<=m;i++) scanf("%d%d%d",&ee[i].u,&ee[i].v,&ee[i].w);
	int T,op,x,y;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&op,&x,&y);
		if(!op){
			if(x==y) {printf("0\n");continue;}
			cnt=1;
			for(int i=0;i<=n;i++) head[i]=0;
			for(int i=1;i<=m;i++)
				add(ee[i].u,ee[i].v,ee[i].w);
			int maxflow=0;
			while(bfs(x,y))
				maxflow+=dinic(x,inf,y);
			printf("%d\n",maxflow);
		}
		else ee[x].w=y;
	}
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1) work1();
	else work2();
	return 0;
}
