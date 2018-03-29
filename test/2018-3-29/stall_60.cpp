#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010
using namespace std;
int n,m,q,k,a[maxn];
int qread(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
//-----------------------------------------------------------
int pos[maxn];
void work1(){
	int l=qread(),r=qread();
	int cnt=0;
	for(int i=l;i<=r;i++)pos[++cnt]=a[i];
	sort(pos+1,pos+cnt+1);
	pos[0]=0;pos[cnt+1]=n+1;cnt++;
	for(int i=0;i<=cnt;i++){
		if(pos[i]-pos[i-1]-1>=k){
			printf("%d\n",pos[i-1]+1);
			return;
		}
	}
	puts("-1");
}
//-----------------------------------------------------------
int root[maxn*40],lc[maxn*40],rc[maxn*40],mn[maxn*40],sz;
void build(int &now,int pre,int l,int r,int pos,int val){
	now=++sz;
	if(l==r){
		mn[now]=val;
		return;
	}
	lc[now]=lc[pre];rc[now]=rc[pre];
	int mid=(l+r)>>1;
	if(pos<=mid)build(lc[now],lc[pre],l,mid,pos,val);
	else build(rc[now],rc[pre],mid+1,r,pos,val);
	mn[now]=min(mn[lc[now]],mn[rc[now]]);
}
int query(int now,int l,int r,int pos){
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(mn[lc[now]]>=pos)return query(rc[now],mid+1,r,pos);
	else return query(lc[now],l,mid,pos);
}
void work2(){
	for(int i=1;i<=m;i++){
		build(root[i],root[i-1],1,n+1,a[i],i);
	}
	int l,r;
	for(int i=1;i<=q;i++){
		l=qread();r=qread();
		int ans=query(root[r],1,n+1,l);
		if(ans>n)puts("-1");
		else printf("%d\n",ans);
	}
}
//-----------------------------------------------------------
int b[maxn*2];
void work3(){
	for(int i=1;i<=m;i++){
		b[i*2]=a[i];
		b[i*2-1]=a[i]-1;
	}
	int mm=m+m;
	for(int i=1;i<=mm;i++){
		build(root[i],root[i-1],1,n,b[i],i);
	}
	int l,r;
	for(int i=1;i<=q;i++){
		l=qread();r=qread();
		l=l*2-1;r=r*2;
		int ans=query(root[r],1,n,l);
		if(ans>=n)puts("-1");
		else printf("%d\n",ans);
	}
}
//-----------------------------------------------------------
int main(){
//	freopen("Cola.txt","r",stdin);freopen("qwq.txt","w",stdout);
	freopen("stall.in","r",stdin);freopen("stall.out","w",stdout);
	n=qread(),m=qread(),q=qread(),k=qread();
	for(int i=1;i<=m;i++)a[i]=qread();
	if(q==1){work1();return 0;}
	if(k==1){work2();return 0;}
	if(k==2){work3();return 0;}
}
