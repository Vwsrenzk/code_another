#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 300010
using namespace std;
int n,m,head[maxn],num,du[maxn],f[maxn],nowin[maxn];
int p,ans;
char s[maxn];
bool vis[maxn],inq[maxn];
struct node{int to,pre,v;}e[maxn*2];
void Insert(int from,int to){
	e[++num].to=to;
	e[num].pre=head[from];
	head[from]=num;
}
bool dfs(int now){
	vis[now]=1;
	inq[now]=1;
	for(int i=head[now];i;i=e[i].pre){
		int to=e[i].to;
		if(inq[to])return 1;
		else if(!vis[to]&&dfs(to))return 1;
	}
	inq[now]=0;
	return 0;
}
queue<int>q;
void tops(){
	for(int i=1;i<=n;i++){
		nowin[i]=du[i];
		if(!du[i])q.push(i);
	}
	while(!q.empty()){
		int now=q.front();q.pop();
		if(s[now]==p)f[now]+=1;
		ans=max(ans,f[now]);
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			nowin[to]--;
			f[to]=max(f[to],f[now]);
			if(!nowin[to])q.push(to);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		Insert(x,y);du[y]++;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&dfs(i)){
			puts("-1");
			return 0;
		}
	}
	for(int i=0;i<26;i++){
		p=i+'a';
		memset(f,0,sizeof(f));
		tops();
	}
	cout<<ans<<endl;
}
