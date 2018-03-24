#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1010
using namespace std;
int n,m,num,ans;
int lca[maxn][maxn],val[maxn][maxn],w[maxn],dep[maxn],fa[maxn],head[maxn];
bool vis[maxn];
struct node{int to,pre;}e[maxn*2];
void Insert(int from,int to){
	e[++num].to=to;
	e[num].pre=head[from];
	head[from]=num;
}
void dfs(int x,int father){
	dep[x]=dep[father]+1;
	fa[x]=father;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		dfs(to,x);
	}
}
int count(int x,int y){
	int res=0;
	int px=x,py=y;
	while(dep[x]!=dep[y]){
		if(dep[x]<dep[y])swap(x,y);
		res^=w[x];
		x=fa[x];
	}
	while(x!=y){
		res^=w[x];res^=w[y];
		x=fa[x];y=fa[y];
	}
	if(x!=y)x=fa[x];
	res^=w[x];
	lca[px][py]=lca[py][px]=x;
	return res;
}
void dfs2(int x,int father){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		dfs2(to,x);
	}
}
int main(){
//	freopen("qwq.txt","r",stdin);freopen("ans.txt","w",stdout);
	freopen("games.in","r",stdin);freopen("games.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		Insert(x,y);Insert(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			val[i][j]=count(i,j);
	while(m--){
		scanf("%d%d",&x,&y);
		memset(vis,0,sizeof(vis));
		dfs2(x,fa[x]);
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if((vis[i]^vis[j])||(dep[lca[i][j]]<=dep[x]&&vis[i]&&vis[j])){
					val[i][j]^=w[x];
					val[i][j]^=y;
				}
				ans+=val[i][j];
			}
		w[x]=y;
		ans*=2;
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
