#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2010
using namespace std;
int n,m,b[maxn];
bool vis[maxn];
long long ans;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
void check(int pos){
	if(pos==1)return;
	for(int i=1;i<=pos;i++)
		for(int j=i+1;j<=pos;j++)
			ans+=gcd(b[i],b[j]);
//	for(int i=1;i<=pos;i++)cout<<b[i]<<' ';cout<<endl;
}
void dfs(int w,int pre,int pos){
	if(w==0){check(pos-1);}
	if(w<pre)return;
	for(int i=pre;i<=w;i++){
		if(vis[i])continue;
		b[pos]=i;
		dfs(w-i,i,pos+1);
	}
}
int main(){
	freopen("zscf.in","r",stdin);freopen("zscf.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		memset(vis,0,sizeof(vis));ans=0;
		scanf("%d",&m);
		int x;
		for(int i=1;i<=m;i++)scanf("%d",&x),vis[x]=1;
		dfs(n,1,1);
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
