#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define maxn 2010
using namespace std;
int pos[maxn],w[maxn],n,ans,now_ans;
bool mp[maxn][maxn],vis[maxn];
void dfs(int x){
	if(x>n){
		ans=now_ans;
		return;
	}
	bool flag=1;
	for(int i=1;i<x;i++)
		if(vis[i]&&!mp[x][i]){
			flag=0;
			break;
		}
	if(flag){
		now_ans++;
		vis[x]=1;
		dfs(x+1);
		now_ans--;
	}
	if(now_ans+n-x>ans){
		vis[x]=0;
		dfs(x+1);
	}
}
int main(){
	freopen("clique.in","r",stdin);
	freopen("clique.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&pos[i],&w[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(abs(pos[i]-pos[j])>=w[i]+w[j]){
				mp[i][j]=1;
				mp[j][i]=1;
			}
	dfs(1);
	printf("%d",ans);
	return 0;
}
