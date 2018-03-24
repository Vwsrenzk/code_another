#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2010
#define mod 1000000007
using namespace std;
int able[maxn],n,w[maxn],f[maxn],gcd[maxn][maxn];
void getw(){
	memset(w,0,sizeof(w));
	w[0]=1;
	for(int i=1;i<=n;i++){
		if(!able[i])continue;
		for(int j=i;j<=n;j++){
			w[j]=w[j]+w[j-i];
			if(w[j]>=mod)w[j]-=mod;
		}
	}
}
void getgcd(){
	for(int i=1;i<maxn;i++)
		gcd[i][0]=gcd[0][i]=i;
	for(int i=1;i<maxn;i++)
		for(int j=1;j<maxn;j++)
		gcd[i][j]=gcd[j%i][i];
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("zscf.in","r",stdin);freopen("zscf.out","w",stdout);
	getgcd();
	while(scanf("%d",&n)!=EOF){
		int m,x;
		scanf("%d",&m);
		for(int i=1;i<=n;i++)able[i]=1;
		for(int i=1;i<=m;i++){
			scanf("%d",&x);
			able[x]=0;
		}
		getw();
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!able[i])continue;
			for(int j=0;j<=n;j++)
				f[j]=(w[j]+(j<i?0:f[j-i]))%mod;
			for(int j=i+1;j<=n;j++){
				if(!able[j])continue;
				int t=0;
				for(int k=1;k*j+i<=n;k++){
					t+=f[n-k*j-i];
					if(t>=mod)t-=mod;
				}
				ans+=1LL*gcd[i][j]*t%mod;
				if(ans>=mod)ans-=mod;
			}
		}
		for(int i=1;2*i<=n;i++){
			if(!able[i])continue;
			for(int j=1;j*i<=n;j++){
				ans+=1LL*(j-1)*i*w[n-j*i]%mod;
				if(ans>=mod)ans-=mod;
			}
		}
		printf("%d\n",(ans+mod)%mod);
	}
	return 0;
}
