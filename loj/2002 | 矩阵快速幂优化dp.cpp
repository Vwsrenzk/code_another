#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 20000010
#define mod 20170408
using namespace std;
int n,m,p,P[maxn/10],tot,f[110];
bool vis[maxn];
struct matrix{
	int a[110][110];
	matrix(){memset(a,0,sizeof(a));}
	matrix operator * (const matrix x)const{
		matrix res;
		for(int i=0;i<p;i++)
			for(int j=0;j<p;j++)
				for(int k=0;k<p;k++)
					res.a[i][j]=(res.a[i][j]+1LL*a[i][k]*x.a[k][j]%mod)%mod;
		return res;
	}
};
void prepare(int n){
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i])P[++tot]=i;
		for(int j=1;j<=tot&&i*P[j]<=n;j++){
			vis[i*P[j]]=1;
			if(i%P[j]==0)break;
		}
	}
}
matrix Pow(matrix x,int y){
	matrix res=x;y--;
	while(y){
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
int solve1(){
	for(int i=1;i<=m;i++)f[i%p]++;
	matrix a;
	for(int i=1;i<=m;i++)a.a[(-i%p+p)%p][0]++;
	for(int i=1;i<p;i++)
		for(int j=0;j<p;j++)
			a.a[j][i]=a.a[(j-1+p)%p][i-1];
	a=Pow(a,n-1);
	int ans=0;
	for(int i=0;i<p;i++)
		ans=(ans+1LL*f[i]*a.a[i][0]%mod)%mod;
	return ans;
}
int solve2(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=m;i++)if(vis[i])f[i%p]++;
	matrix a;
	for(int i=1;i<=m;i++)
		if(vis[i])a.a[(-i%p+p)%p][0]++;
	for(int i=1;i<p;i++)
		for(int j=0;j<p;j++)
		a.a[j][i]=a.a[(j-1+p)%p][i-1];
	a=Pow(a,n-1);
	int ans=0;
	for(int i=0;i<p;i++)
		ans=(ans+1LL*f[i]*a.a[i][0]%mod)%mod;
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	prepare(m);
	int x=solve1(),y=solve2();
	printf("%d",(x-y+mod)%mod);
	return 0;
}
