#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
using namespace std;
int T,head[maxn],num=1,ans=0,n;
struct node{int to,pre,v;}e[maxn*2];
void Insert(int from,int to){
	e[++num].to=to;
	e[num].pre=head[from];
	head[from]=num;
}
//----------------------------------------------------------
int path[maxn],dep[maxn],fa[maxn][20],col,color[maxn],precol[maxn];
bool vis[maxn],flag[maxn];
void dfs1(int x,int father){
	fa[x][0]=father;
	dep[x]=dep[father]+1;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		path[to]=i;
		dfs1(to,x);
	}
}
void makefa(){
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}
int get(int x,int delta){
	for(int i=0;i<=18;i++)
		if(delta&(1<<i))x=fa[x][i];
	return x;
}
int getlca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	x=get(x,dep[x]-dep[y]);
	for(int i=18;i>=0;i--){
		if(fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	}
	if(x==y)return x;
	else return fa[x][0];
}
void change(int x,int y,int lca){
	int now=x;
	while(now!=lca){
		e[path[now]].v=1;
		e[path[now]^1].v=1;
		flag[now]=1;
		now=fa[now][0];
	}
	now=y;
	while(now!=lca){
		e[path[now]].v=1;
		e[path[now]^1].v=1;
		flag[now]=1;
		now=fa[now][0];
	}
	flag[lca]=1;
}
void dfs2(int x,int father){
	precol[x]=col;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		if(e[i].v||vis[to]||flag[to])continue;
		dfs2(to,x);
	}
}
void dfs3(int x,int father){
	color[x]=col;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		if(e[i].v||vis[to]||flag[to])continue;
		dfs3(to,x);
	}
}
void solve1(){
	while(T--){
		num=1;ans=0;
		memset(head,0,sizeof(head));
		memset(path,0,sizeof(path));
		memset(fa,0,sizeof(fa));
		memset(dep,0,sizeof(dep));
		scanf("%d",&n);
		int x,y;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			Insert(x,y);Insert(y,x);
		}
		dfs1(1,0);
		makefa();
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int lca=getlca(i,j);
				memset(vis,0,sizeof(vis));
				memset(flag,0,sizeof(flag));
				for(int k=1;k<=num;k++)e[k].v=0;
				change(i,j,lca);
				memset(precol,0,sizeof(precol));
				col=0;
				for(int k=1;k<=n;k++){
					if(vis[k]||flag[k])continue;
					col++;
					dfs2(k,0);
				}
				ans=max(ans,col);
				for(int ii=1;ii<=n;ii++){
					for(int jj=ii;jj<=n;jj++){
						if(precol[ii]&&precol[jj]&&(precol[ii]==precol[jj])){
							int lca2=getlca(ii,jj);
							change(ii,jj,lca2);
							memset(vis,0,sizeof(vis));
							memset(color,0,sizeof(color));
							col=0;
							for(int k=1;k<=n;k++){
								if(vis[k]||flag[k])continue;
								col++;
								dfs3(k,0);
							}
							ans=max(ans,col);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
//----------------------------------------------------------
void solve2(){
	int p0,p1,h0,h1,x,y;
	while(T--){
		scanf("%d%d%d%d%d",&n,&p0,&p1,&h0,&h1);
		memset(head,0,sizeof(head));num=0;
		memset(path,0,sizeof(path));
		memset(fa,0,sizeof(fa));
		memset(dep,0,sizeof(dep));
		memset(e,0,sizeof(e));
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			Insert(x,y);Insert(y,x);
		}
		dfs1(1,0);makefa();
		int lca1=getlca(p0,p1),lca2=getlca(h0,h1);
		memset(vis,0,sizeof(vis));
		memset(flag,0,sizeof(flag));
		change(p0,p1,lca1);change(h0,h1,lca2);
		col=0;
		memset(precol,0,sizeof(precol));
		for(int k=1;k<=n;k++){
			if(vis[k]||flag[k])continue;
			col++;
			dfs2(k,0);
		}
		printf("%d\n",col);
	}
}


//----------------------------------------------------------
int main(){
//	freopen("Cola.txt","r",stdin);//freopen("qwq.txt","w",stdout);
	freopen("treediagram.in","r",stdin);freopen("treediagram.out","w",stdout);
	int x;
	scanf("%d%d",&T,&x);
	if(x==0){solve1();return 0;}
	if(x==2){solve2();return 0;}
	if(x==1){solve3();return 0;}
}
