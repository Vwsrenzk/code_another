#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500010
#define INF 1000
using namespace std;
int R,C,n,sz,m;
int lc[maxn*30],rc[maxn*30],root[maxn],sum[maxn*30],w[maxn*30],val[maxn];
void build(int l,int r,int x,int &y,int v){
	y=++sz;
	if(l==r){
		sum[y]=sum[x]+v;
		w[y]=w[x]+1;
		return;
	}
	int mid=(l+r)>>1;
	lc[y]=lc[x];rc[y]=rc[x];
	if(v<=mid)build(l,mid,lc[x],lc[y],v);
	else build(mid+1,r,rc[x],rc[y],v);
	sum[y]=sum[lc[y]]+sum[rc[y]];
	w[y]=w[lc[y]]+w[rc[y]];
}
int query(int l,int r,int x,int y,int k){
	if(l==r) return (sum[y]-sum[x])/(w[y]-w[x])*k;
	int mid=l+r>>1,tmp=w[lc[y]]-w[lc[x]];
	if(k<=tmp) return query(l,mid,lc[x],lc[y],k);
	return sum[lc[y]]-sum[lc[x]]+query(mid+1,r,rc[x],rc[y],k-tmp);
}
void work1(){
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		build(1,INF,root[i-1],root[i],val[i]);
	}
	int xx,x,y,h;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d%d",&xx,&x,&xx,&y,&h);
		int len=y-x+1,ans;
		int l=1,r=len;
		int sum=query(1,INF,root[x-1],root[y],len);
		if(sum<h){puts("Poor QLW");continue;}
		while(l<=r){
			int mid=(l+r)>>1;
			int nowsum=sum;
			if(mid==len){
				ans=len;break;
			}
			int kk=query(1,INF,root[x-1],root[y],len-mid);
			nowsum-=kk;
			if(nowsum>=h)ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
}
int main(){
	scanf("%d%d%d",&R,&C,&m);n=C;
	if(R==1)work1();
//	else work2();
	return 0;
}

/*


1 10 4
2 6 3 9 6 9 4 5 4 2
1 4 1 7 16 
1 7 1 10 10
1 1 1 5 4
1 3 1 4 13


*/
