#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
using namespace std;
int n,m,opl,opr,opv,opt,opmod,opll,oplr;
struct node{
	int l,r;
	long long v,mx;
}tr[maxn*4];
void build(int l,int r,int k){
	tr[k].l=l;tr[k].r=r;
	if(l==r){
		int x;
		scanf("%d",&x);
		tr[k].v=tr[k].mx=x;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,k<<1);build(mid+1,r,k<<1|1);
	tr[k].v=tr[k<<1].v+tr[k<<1|1].v;
	tr[k].mx=max(tr[k<<1].mx,tr[k<<1|1].mx);
}
long long query(int l,int r,int k){
	if(l>=opl&&r<=opr){
		return tr[k].v;
	}
	int mid=(l+r)>>1;
	long long res=0;
	if(opl<=mid)res+=query(l,mid,k<<1);
	if(opr>mid)res+=query(mid+1,r,k<<1|1);
	return res;
}
void change(int l,int r,int k){
	if(l==r){
		tr[k].v=tr[k].mx=opv;
		return;
	}
	int mid=(l+r)>>1;
	if(opt<=mid)change(l,mid,k<<1);
	if(opt>mid)change(mid+1,r,k<<1|1);
	tr[k].v=tr[k<<1].v+tr[k<<1|1].v;
	tr[k].mx=max(tr[k<<1].mx,tr[k<<1|1].mx);
}
void Mod(int l,int r,int k){
	if(l==r){
		if(tr[k].v>=opmod)tr[k].v%=opmod,tr[k].mx%=opmod;
		return;
	}
	if(l>=opl&&r<=opr){
		if(tr[k].mx<opmod)return;
		else {
			int mid=(l+r)>>1;
			Mod(l,mid,k<<1);Mod(mid+1,r,k<<1|1);
			tr[k].v=tr[k<<1].v+tr[k<<1|1].v;
			tr[k].mx=max(tr[k<<1].mx,tr[k<<1|1].mx);
			return;
		}
	}
	int mid=(l+r)>>1;
	if(opl<=mid)Mod(l,mid,k<<1);
	if(opr>mid)Mod(mid+1,r,k<<1|1);
	tr[k].v=tr[k<<1].v+tr[k<<1|1].v;
	tr[k].mx=max(tr[k<<1].mx,tr[k<<1|1].mx);
}
int main(){
//	freopen("data.txt","r",stdin);
	freopen("mod.in","r",stdin);freopen("mod.out","w",stdout); 
	scanf("%d%d",&n,&m);
	build(1,n,1);
	int op;
	while(m--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&opl,&opr);
			cout<<query(1,n,1)<<endl;
		}
		if(op==2){
			scanf("%d%d%d",&opl,&opr,&opmod);
			Mod(1,n,1);
		}
		if(op==3){
			scanf("%d%d",&opt,&opv);
			change(1,n,1);
		}
	}
	return 0;
}
