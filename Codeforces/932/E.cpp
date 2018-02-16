#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5010
#define mod 1000000007
using namespace std;
int n,m,f[maxn],p;
long long Pow(long long x,long long y){
	if(y<=0)return 1;
	long long res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	f[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=i;j>=0;j--)
			f[j]=(1LL*f[j]*j%mod+1LL*f[j-1]*(n-j+1)%mod)%mod;
		f[0]=0;
	}
	for(int i=1;i<=m;i++)
		p=(p+1LL*f[i]*Pow(2,n-i)%mod)%mod;
	printf("%d",p);
	return 0;
}
