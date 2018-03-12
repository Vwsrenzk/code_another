#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 50010
using namespace std;
int n,m,p,c,a[maxn];
long long sum[maxn*4];
struct node{int op,x,y;}q[maxn];
bool flag=1;
//-----------------------------------------------------------------------
void build(int k,int l,int r){
	if(l==r){
		sum[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=(sum[k<<1]+sum[k<<1|1])%p;
}
long long query(int k,int l,int r,int opl,int opr){
	if(l>=opl&&r<=opr)return sum[k];
	int mid=(l+r)>>1;
	long long res=0;
	if(opl<=mid)res+=query(k<<1,l,mid,opl,opr);
	if(opr>mid)res+=query(k<<1|1,mid+1,r,opl,opr);
	return res;
}
void work1(){
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int ans=query(1,1,n,q[i].x,q[i].y)%p;
		printf("%d\n",ans);
	}
}
//-----------------------------------------------------------------------
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1LL*res*x%p;
		x=1LL*x*x%p;
		y>>=1;
	}
	return res;
}
int getphi(int x){//单个欧拉函数 
    int w=(int)sqrt(x+0.5);
    int ans=x;
    for(int i=2;i<=w;i++)if(x%i==0){
        ans=ans/i*(i-1);
        while(x%i==0)x/=i;
    }
    if(x>1)ans=ans/x*(x-1);
}
void modify(int k,int l,int r,int opx,int opv){
	if(l==r){sum[k]=opv;return;}
	int mid=(l+r)>>1;
	if(opx<=mid)modify(k<<1,l,mid,opx,opv);
	else modify(k<<1|1,mid+1,r,opx,opv);
	sum[k]=(sum[k<<1]+sum[k<<1|1])%p;
}
void work2(){
	int phi=getphi(p);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		if(q[i].op==0){
			a[q[i].x]=Pow(c,a[q[i].x]);
			modify(1,1,n,q[i].x,a[q[i].x]);
		}
		else {
			int ans=query(1,1,n,q[i].x,q[i].y)%p;
			printf("%d\n",ans);
		}
	}
}

//-----------------------------------------------------------------------
int main(){
//	freopen("Cola.txt","r",stdin);freopen("out.txt","w",stdout);
	freopen("verbinden.in","r",stdin);freopen("verbinden.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&c);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i].op,&q[i].x,&q[i].y);
		if(q[i].op==0)flag=0;
	}
	if(flag){work1();return 0;}//没有修改操作 
	work2();return 0;
}
