#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010
using namespace std;
int lc[maxn*60],rc[maxn*60],addv[maxn*60],minv[maxn*60],cnt;
int root[maxn],n,m;
struct node{
	int v,id;
	bool operator < (const node x)const{
		return v<x.v;
	}
}a[maxn];
void update(int k,int l,int r){
	if(l==r)minv[k]=addv[k];
	else minv[k]=addv[k]+min(minv[lc[k]],minv[rc[k]]);
}
void build(int &k,int l,int r,int opl,int opr){
	if(r<opl||l>opr)return;
	lc[cnt]=lc[k];rc[cnt]=rc[k];addv[cnt]=addv[k];minv[cnt]=minv[k];
	k=cnt++;
	if(l>=opl&&r<=opr)++addv[k];
	else {
		int mid=(l+r)>>1;
		build(lc[k],l,mid,opl,opr);
		build(rc[k],mid+1,r,opl,opr);
	}
	update(k,l,r);
}
int query(int k,int l,int r,int opl,int opr){
	if(r<opl||l>opr)return 10000000;
	if(l>=opl&&r<=opr)return minv[k];
	else {
		int mid=(l+r)>>1;
		return addv[k]+min(query(lc[k],l,mid,opl,opr),query(rc[k],mid+1,r,opl,opr));
	}
}
int main(){
	freopen("music.in","r",stdin);freopen("music.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].v),a[i].id=i;
	sort(a+1,a+n+1);
	cnt=1,root[0]=0;
	for(int i=1;i<=n;i++)
		build(root[i]=root[i-1],1,n,max(1,a[i].id-m+1),a[i].id);
	int q,lastans=0;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d%d",&l,&r,&a[0].v);
		a[0].v^=lastans;
		int t=lower_bound(a+1,a+n+1,a[0])-a-1;
		lastans=query(root[t],1,n,l,r);
		printf("%d\n",lastans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
