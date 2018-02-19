#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010
using namespace std;
int n;
struct node{
	int l,r;
	bool operator < (const node &x)const{
		return l<x.l;
	}
}q[maxn];
bool ok[maxn];
bool check(int x,int y){
	if(q[x].l<=q[y].l&&q[x].r>=q[y].r)return 0;
	return 1;
}
int main(){
	freopen("clique.in","r",stdin);freopen("clique.out","w",stdout);
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		q[i].l=x-y;
		q[i].r=x+y;
	}
	sort(q+1,q+n+1);
	int m=0;
	for(int i=1;i<=n;i++){
		while(m&&q[i].r<q[m].r)m--;
		q[++m]=q[i];
	}
	int p=1,ans=1;
	for(int i=2;i<=m;i++)
		if(q[i].l>=q[p].r){
			ans++;
			p=i;
		}
	printf("%d",ans);
}
