/*source bzoj3585*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#define maxn 200010
using namespace std;
int a[maxn],n,m,t,b[maxn];
int qread(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
//------------------------------------------------------------------
void work1(){
	int l,r,cnt;
	while(m--){
		cnt=0;
		l=qread();r=qread();
		for(int i=l;i<=r;i++)b[++cnt]=a[i];
		sort(b+1,b+cnt+1);
		b[0]=-1;
		bool flag=0;
		for(int i=1;i<=cnt;i++)
			if(b[i]-b[i-1]>1){
				printf("%d\n",b[i-1]+1);
				flag=1;break;
			}
		if(!flag)printf("%d\n",b[cnt]+1);
	}
}
//------------------------------------------------------------------
int block,pos[maxn],vis[maxn];
struct node{
	int l,r,v,id;
	bool operator < (const node &y)const{
		if(pos[l]==pos[y.l])return r<y.r;
//		if(l==y.l)return r<y.r;
		return l<y.l;
	}
}q[maxn];
bool cmp(node x,node y){return x.id<y.id;}
void update(int p,int v){
	vis[a[p]]+=v;
}
void solve(){
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(r<q[i].r)r++,update(r,1);
		while(r>q[i].r)update(r,-1),r--;
		while(l<q[i].l)update(l,-1),l++;
		while(l>q[i].l)l--,update(l,1);
		
		for(int j=0;j<=1e9;j++){
			if(vis[j]==0){q[i].v=j;break;}
		}
	}
}
void work2(){
	block=(int)(sqrt(n));
	for(int i=1;i<=n;i++)pos[i]=(i-1)/block+1;
	for(int i=1;i<=m;i++)q[i].l=qread(),q[i].r=qread(),q[i].id=i;
	sort(q+1,q+m+1);
	solve();
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)printf("%d\n",q[i].v);
}
//------------------------------------------------------------------
int main(){
//	freopen("Cola.txt","r",stdin);freopen("qwq.txt","w",stdout);
	freopen("mex.in","r",stdin);freopen("mex.out","w",stdout);
	n=qread();m=qread();t=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
		if(a[i]>n)a[i]=n;
	}
	if(n<=1000&&m<=1000)work1();
	else work2();
	fclose(stdin);fclose(stdout);
	return 0;
}
