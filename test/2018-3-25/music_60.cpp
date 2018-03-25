#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200010
using namespace std;
int n,m,Q,a[maxn];
int qread(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
void work1(){
	int lastans=0;
	int l,r,q,qi;
	while(Q--){
		l=qread();r=qread();q=qread();
		qi=q^lastans;
		int ans=0x7fffffff;
		for(int i=l;i<=r;i++){
			int cnt=0;
			for(int j=0;j<m;j++)
				if(a[i+j]<qi)cnt++;
			ans=min(ans,cnt);
		}
		lastans=ans;
		printf("%d\n",ans);
	}
}
int mx[maxn][20];
int query(int l,int r){
	int k=0;
    while(1<<k+1<=r-l+1)k++;
    return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
void work2(){
	for(int i=1;i<=n;i++)mx[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
	int lastans=0,l,r,q,qi;
	while(Q--){
		l=qread();r=qread();q=qread();
		qi=q^lastans;
		int Max=query(l,r);
		if(Max<qi)puts("1"),lastans=1;
		else puts("0"),lastans=0;
	}
}
int main(){
	freopen("music.in","r",stdin);freopen("music.out","w",stdout);
//	freopen("Cola.txt","r",stdin);freopen("qwq.txt","w",stdout);
	n=qread();m=qread();
	for(int i=1;i<=n;i++)a[i]=qread();
	Q=qread();
	if(m==1){work2();return 0;}
	work1();return 0;
}
