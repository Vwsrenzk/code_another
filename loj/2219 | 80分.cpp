#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000010
using namespace std;
int n,num,head[maxn],fa[maxn],dep[maxn],top[maxn],sz[maxn],son[maxn];
int m,a[maxn];
struct node{int to,pre;}e[maxn*2];
void Insert(int from,int to){
	e[++num].to=to;
	e[num].pre=head[from];
	head[from]=num;
}
void dfs1(int x,int father){
	fa[x]=father;
	sz[x]=1;
	dep[x]=dep[father]+1;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		dfs1(to,x);
		sz[x]+=sz[to];
		if(sz[son[x]]<sz[to])son[x]=to;
	}
}
void dfs2(int x,int father){
	top[x]=father;
	if(son[x])dfs2(son[x],father);
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==son[x]||to==fa[x])continue;
		dfs2(to,to);
	}
}
int getlca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int main(){
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		Insert(x,y);Insert(y,x);
	}
	dfs1(1,0);dfs2(1,1);
	int q;scanf("%d",&q);
	while(q--){
		scanf("%d",&m);
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		long long ans=0,ans1=1000000000000,ans2=0;
		for(int i=1;i<=m;i++)
			for(int j=i+1;j<=m;j++){
				int lca=getlca(a[i],a[j]);
				long long dis=dep[a[i]]-dep[lca]+dep[a[j]]-dep[lca];
				ans+=dis;
				ans1=min(ans1,dis);
				ans2=max(ans2,dis);
			}
		printf("%lld %lld %lld\n",ans,ans1,ans2);
	}
	return 0;
}
