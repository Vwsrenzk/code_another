#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
using namespace std;
int f[110][110],n,mod,K,r,w[maxn],head[maxn],num,fa[maxn],dep[maxn];
int top[maxn],sz[maxn],son[maxn];
struct node{int to,pre;}e[maxn*2];
int qread(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
void Insert(int from,int to){
	e[++num].to=to;
	e[num].pre=head[from];
	head[from]=num;
}
void dfs1(int now,int father){
	fa[now]=father;
	dep[now]=dep[father]+1;
	sz[now]=1;
	for(int i=head[now];i;i=e[i].pre){
		int to=e[i].to;
		if(to==father)continue;
		dfs1(to,now);
		sz[now]+=sz[to];
		if(sz[to]>sz[son[now]])son[now]=to;
	}
}
void dfs2(int now,int father){
	top[now]=father;
	if(son[now])dfs2(son[now],father);
	for(int i=head[now];i;i=e[i].pre){
		int to=e[i].to;
		if(to==son[now]||to==fa[now])continue;
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
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1LL*res*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return res;
}
int count(int x,int y){
	int lca=getlca(x,y);
	int now=x,cnt=-1,res=0;
	while(now!=lca){
		cnt++;
		res+=1LL*w[now]*Pow(K,cnt)%mod;
		if(res>=mod)res-=mod;
		now=fa[now];
	}
	cnt+=dep[y]-dep[lca]+1;
	now=y;
	cnt++;
	while(now!=lca){
		cnt--;
		res+=1LL*w[now]*Pow(K,cnt)%mod;
		if(res>=mod)res-=mod;
		now=fa[now];
	}
	cnt--;
	res+=1LL*w[now]*Pow(K,cnt)%mod;
	if(res>=mod)res-=mod;
	return res;
}
bool eq(int x){return x==r;}
void work1(){
	int ans=0;
	dfs1(1,0);dfs2(1,1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			f[i][j]=count(i,j);
//			cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if((eq(f[i][j]) == eq(f[i][k])) && (eq(f[i][j]) == eq(f[j][k])))ans++;
	printf("%d",ans);
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("gbxf.in","r",stdin);freopen("gbxf.out","w",stdout);
	n=qread();mod=qread();K=qread();r=qread();
	for(int i=1;i<=n;i++)w[i]=qread();
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		Insert(x,y);Insert(y,x);
	}
	work1();
	fclose(stdin);fclose(stdout);
	return 0;
}
