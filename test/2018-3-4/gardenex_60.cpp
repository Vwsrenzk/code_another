#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100010
#define INF 1000000000
using namespace std;
int n,m,head[maxn],num,dis[maxn];
bool vis[maxn];
struct node{int to,pre,v;}e[maxn*2];
void Insert(int from,int to,int v){
	e[++num].to=to;
	e[num].v=v;
	e[num].pre=head[from];
	head[from]=num;
}
void spfa(int s){
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;vis[s]=1;q.push(s);
	while(!q.empty()){
		int now=q.front();q.pop();vis[now]=0;
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]>dis[now]+e[i].v){
				dis[to]=dis[now]+e[i].v;
				if(!vis[to]){
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
int top[maxn],son[maxn],sz[maxn],fa[maxn],dfn[maxn],id,dep[maxn],a[maxn],belong[maxn];
int val[maxn*4];
void dfs1(int x,int father){
	sz[x]=1;
	fa[x]=father;
	dep[x]=dep[father]+1;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		a[to]=e[i].v;
		dfs1(to,x);
		sz[x]+=sz[to];
		if(!son[x]||(sz[son[x]]<sz[to]))son[x]=to;
	}
}
void dfs2(int x,int father){
	top[x]=father;
	dfn[x]=++id;
	belong[id]=x;
	if(son[x])dfs2(son[x],father);
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if((to==son[x])||(to==fa[x]))continue;
		dfs2(to,to);
	}
}
void build(int l,int r,int k){
	if(l==r){
		val[k]=a[belong[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,k<<1);build(mid+1,r,k<<1|1);
	val[k]=val[k<<1]+val[k<<1|1];
}
int query_sum(int k,int l,int r,int opl,int opr){
	if(l>=opl&&r<=opr)return val[k];
	int mid=(l+r)>>1;
	int res=0;
	if(opl<=mid)res+=query_sum(k<<1,l,mid,opl,opr);
	if(opr>mid)res+=query_sum(k<<1|1,mid+1,r,opl,opr);
	return res;
}
int query(int x,int y){
	int res=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res+=query_sum(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	res+=query_sum(1,1,n,dfn[x],dfn[y]);
	res-=a[x];
	return res;
}
void work1(){
	dfs1(1,0);dfs2(1,1);
	build(1,n,1);
	int T;
	scanf("%d",&T);
	int x,y;
	while(T--){
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y));
	}
	return;
}
void work2(){
	int T;scanf("%d",&T);
	int x,y;
	while(T--){
		scanf("%d%d",&x,&y);
		spfa(x);
		if(dis[y]>INF)puts("-1");
		else printf("%d\n",dis[y]);
	}
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("gardenex.in","r",stdin);freopen("gardenex.out","w",stdout);
	int k,x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		Insert(x,y,z);Insert(y,x,z);
	}
	if(k==0){
		work1();
		fclose(stdin);fclose(stdout);
		return 0;
	}
	else {
		work2();
		fclose(stdin);fclose(stdout);
		return 0;
	}
}
