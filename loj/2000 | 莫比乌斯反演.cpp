#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000010
#define mod 1000000007
using namespace std;
int T,n,m,f[maxn],p[maxn],cnt;
bool vis[maxn];
long long g[maxn],mu[maxn];
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1LL*res*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return res;
}
void prepare(){
	mu[1]=1;f[0]=0;f[1]=g[0]=g[1]=1;
	for(int i=2;i<=1000000;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
		g[i]=1;
		if(!vis[i])p[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&i*p[j]<=1000000;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){mu[i*p[j]]=0;break;}
			mu[i*p[j]]=-mu[i];
		}
	}
	for(int i=1;i<=1000000;i++){
		long long inv=Pow(f[i],mod-2);
		for(int j=i,k=1;j<=1000000;j+=i,k++)
			if(mu[k])g[j]=g[j]*(mu[k]==1?f[i]:inv)%mod;
		g[i]=g[i]*g[i-1]%mod;
	}
}
void solve(int n,int m){
	if(n>m)swap(n,m);
	long long ans=1;
	for(int i=1,j;i<=n;i=j+1){
		j=min(n/(n/i),m/(m/i));
		ans=(ans*Pow(g[j]*Pow(g[i-1],mod-2)%mod,1LL*(n/i)*(m/i)%(mod-1)))%mod;
	}
	cout<<ans<<endl;
}
int main(){
	prepare();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		solve(n,m);
	}
}
