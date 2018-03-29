#include<iostream>
#include<cstdio>
#define mod 1000000007
using namespace std;
int n,m,r,c,fac[200010],inv[200010];
long long k;
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1LL*res*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return res;
}
long long C(int n,int m){
	if(m<0||m>n)return 0;
	return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int Calc(int a,int b){
	if(a>r||b>c||(r-a)&1||(c-b)&1)return 0;
	int r1=(r-a)/2,c1=(c-b)/2;
	return C(n,a)*C(m,b)%mod*C(r1+n-1,n-1)%mod*C(c1+m-1,m-1)%mod;
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("matrix.in","r",stdin);freopen("matrix.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&r,&c);cin>>k;
	int ans=0;
	fac[0]=inv[0]=1;
	for(int i=1;i<=200000;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		inv[i]=Pow(fac[i],mod-2);
	}
	for(long long i=0;i<=n;i++){
		if(i*2!=n){
			long long j=(k-m*i)/(n-2*i);
			if(j>=0&&j<=m&&(m-j)*i+(n-i)*j==k){
				ans+=Calc(i,j);
				if(ans>=mod)ans-=mod;
			}
		}
		else if(k==i*m){
			for(int j=0;j<=m;j++){
				ans+=Calc(i,j);
				if(ans>=mod)ans-=mod;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
