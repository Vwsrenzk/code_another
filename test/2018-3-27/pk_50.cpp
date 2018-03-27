#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
#ifdef WIN32
#define PLL "%I64d"
#else
#define PLL "%lld"
#endif
using namespace std;
int n,m,a[maxn],cnt[1000010];
long long val[maxn*8];
struct node{int l,r,v,op;}p[maxn];
int qread(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
//----------------------------------------------------------------
void work0(){
	for(int i=1;i<=m;i++){
		if(p[i].op==1){
			for(int j=p[i].l;j<=p[i].r;j++)
				if(a[j]%p[i].v==0)a[j]/=p[i].v;
		}
		else {
			long long ans=0;
			for(int j=p[i].l;j<=p[i].r;j++)
				ans+=a[j];
			printf(PLL"\n",ans);
		}
	}
}
//-----------------------------------------------------------------
void build(int k,int l,int r){
	if(l==r){
		val[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	val[k]=val[k<<1]+val[k<<1|1];
}
void modify(int k,int l,int r,int opx,int opv){
	if(l==r){
		val[k]=opv;
		return;
	}
	int mid=(l+r)>>1;
	if(opx<=mid)modify(k<<1,l,mid,opx,opv);
	else modify(k<<1|1,mid+1,r,opx,opv);
	val[k]=val[k<<1]+val[k<<1|1];
}
long long query(int k,int l,int r,int opl,int opr){
	if(l>=opl&&r<=opr)return val[k];
	int mid=(l+r)>>1;
	long long res=0;
	if(opl<=mid)res+=query(k<<1,l,mid,opl,opr);
	if(opr>mid)res+=query(k<<1|1,mid+1,r,opl,opr);
	return res;
}
void work1(){
	build(1,1,n);
	for(int i=1;i<=m;i++){
		if(p[i].op==1){
			int pos=p[i].l;
			if(a[pos]%p[i].v==0){
				a[pos]/=p[i].v;
				modify(1,1,n,pos,a[pos]);
			}
		}
		else {
			printf(PLL"\n",query(1,1,n,p[i].l,p[i].r));
		}
	}
}
//-----------------------------------------------------------------
int main(){
	freopen("pk.in","r",stdin);freopen("pk.out","w",stdout);
//	freopen("Cola.txt","r",stdin);freopen("qwq.txt","w",stdout);
	n=qread();m=qread();
	for(int i=1;i<=n;i++)a[i]=qread();
	bool flag1=1,flag2=1;
	for(int i=1;i<=m;i++){
		p[i].op=qread();
		if(p[i].op==1){
			p[i].l=qread();
			p[i].r=qread();
			p[i].v=qread();
			if(p[i].l!=p[i].r)flag1=0;
			if((p[i].l != 1) || (p[i].r != n))flag2=0;
		}
		else {
			p[i].l=qread();
			p[i].r=qread();
		}
	}
	if(flag1){work1();return 0;}
	work0();return 0;
}
