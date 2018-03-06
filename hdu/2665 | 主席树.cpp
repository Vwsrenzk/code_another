#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;
int root[maxn],n,lc[maxn*20],rc[maxn*20],sum[maxn*20],a[maxn],h[maxn],m,cnt,tot;
void discrete(){
	sort(h+1,h+n+1);
	cnt=unique(h+1,h+n+1)-(h+1);
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(h+1,h+cnt+1,a[i])-h;
}
int query(int l,int r,int x,int y,int k){
	if(l==r)return l;
	int mid=(l+r)>>1;
	int tmp=sum[lc[y]]-sum[lc[x]];
	if(k<=tmp)return query(l,mid,lc[x],lc[y],k);
	else return query(mid+1,r,rc[x],rc[y],k-tmp);
}
void build(int l,int r,int x,int &y,int v){
	y=++tot;
	sum[y]=sum[x]+1;
	lc[y]=lc[x];rc[y]=rc[x];
	if(l==r)return;
	int mid=(l+r)>>1;
	if(v<=mid)build(l,mid,lc[x],lc[y],v);
	else build(mid+1,r,rc[x],rc[y],v);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		memset(root,0,sizeof(root));
		tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),h[i]=a[i];
		discrete();
		for(int i=1;i<=n;i++)build(1,cnt,root[i-1],root[i],a[i]);
		int x,y,k;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&k);
			printf("%d\n",h[query(1,cnt,root[x-1],root[y],k)]);
		}
	}
}
