#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2010
using namespace std;
int n,m,r,c,k,a[maxn],b[maxn],ans;
void work(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt+=((a[i]+b[j])&1);
		}
	}
	if(cnt==k)ans++;
}
void dfs2(int pos,int s){
	if(s==0){work();return;}
	if(pos>m)return;
	for(int i=0;i<=s;i++){
		b[pos]=i;
		dfs2(pos+1,s-i);
		b[pos]=0;
	}
}
void dfs1(int pos,int s){
	if(s==0){dfs2(1,c);return;}
	if(pos>n)return;
	for(int i=0;i<=s;i++){
		a[pos]=i;
		dfs1(pos+1,s-i);
		a[pos]=0;
	}
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("matrix.in","r",stdin);freopen("matrix.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&r,&c,&k);
	dfs1(1,r);
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
