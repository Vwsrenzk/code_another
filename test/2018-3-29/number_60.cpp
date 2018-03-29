#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
using namespace std;
long long dp[2][2][2],n,dp1[2][2];
int Pow(int x,long long y){
	int res=1;
	while(y){
		if(y&1)res=1LL*x*res%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>n;
	dp[0][0][0]=1;dp1[0][0]=1;
	for(int i=1;i<=n;i++){
		memset(dp[i&1],0,sizeof(dp[i&1]));
		memset(dp1[i&1],0,sizeof(dp1[i&1]));
		for(int j=0;j<=1;j++){
			dp1[i&1][j]=(dp1[(i-1)&1][j^1]+dp1[(i-1)&1][j]*3)%mod;
			for(int k=0;k<=1;k++){
				dp[i&1][j][k]=(dp[(i-1)&1][j][k]*3%mod+dp[(i-1)&1][j^1][k]+dp[(i-1)&1][j][k^1])%mod;
			}
		}
		
	}
	long long ans=0;
	ans=((dp[n&1][0][0]-2LL*dp1[n&1][0]+Pow(3,n))%mod+mod)%mod;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
