#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
using namespace std;
int head[maxn],col[maxn],fa[maxn],dep[maxn],sz[maxn],top[maxn],son[maxn],count[maxn];
int n,m,num,cnt,leaf[maxn],t;
struct node{int to,pre;}e[maxn*2];
void Insert(int from,int to){
	e[++num].to=to;
	e[num].pre=head[from];
	head[from]=num;
}
void dfs1(int x,int father){
	dep[x]=dep[father]+1;
	fa[x]=father;
	sz[x]=1;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		dfs1(to,x);
		sz[x]+=sz[to];
		if(!son[x]||(sz[son[x]]<sz[to]))son[x]=to;
	}
}
void dfs2(int x,int father){
	top[x]=father;
	if(son[x])dfs2(son[x],father);
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if((to==fa[x])||(to==son[x]))continue;
		dfs2(to,to);
	}
}
void work1(){
	int x;
	scanf("%d",&x);
	cnt++;
	int now=x;
	while(now){
		col[now]=cnt;
		now=fa[now];
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
void work2(){
	int x,y;
	scanf("%d%d",&x,&y);
	int z=lca(x,y);
	memset(count,0,sizeof(count));
	int now=x;
	int tot=0;
	while(now!=fa[z]){
		count[col[now]]++;
		if(count[col[now]]==1)tot++;
		now=fa[now];
	}
	now=y;
	while(now!=fa[z]){
		count[col[now]]++;
		if(count[col[now]]==1)tot++;
		now=fa[now];
	}
	printf("%d\n",tot);
}
void dfs3(int x,int nu){
	count[col[x]]++;
	if(count[col[x]]==1)nu++;
	bool flag=0;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==fa[x])continue;
		flag=1;
		dfs3(to,nu);
	}
	count[col[x]]--;
	if(flag==0){//x是叶子节点 
		leaf[++t]=nu;
	}
}
void work3(){
	int x,tot=0;t=0;
	scanf("%d",&x);
	memset(count,0,sizeof(count));
	int now=fa[x];
	while(now!=0){
		count[col[now]]++;
		if(count[col[now]]==1)tot++;
		now=fa[now];
	}
	dfs3(x,0);
	int mx=0;
	for(int i=1;i<=t;i++){
		if(leaf[i]>mx)mx=leaf[i];
	}
	int ans=mx+tot;
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	int op,x,y;
	for(int i=1;i<=n;i++)col[i]=i;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		Insert(x,y);Insert(y,x);
	}
	cnt=n;
	dfs1(1,0);dfs2(1,1);
	while(m--){
		scanf("%d",&op);
		if(op==1)work1();
		else if(op==2)work2();
		else work3();
	}
	return 0;
}
