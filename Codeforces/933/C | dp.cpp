#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2010
using namespace std;
int n,m,gg[maxn][2][2],f[maxn][2][maxn][2],dp[maxn][2];
bool a[maxn];
int main(){
	int ans=0;
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){scanf("%d",&x);a[i]=x-1;}
	for(int i=1;i<=n;i++){
		gg[i][0][0]=gg[i-1][0][0]+(a[i]==0);
		gg[i][0][1]=gg[i-1][0][1]+(a[i]==1);
	}
	for(int i=n;i>=1;i--){
		gg[i][1][0]=gg[i+1][1][0]+(a[i]==0);
		gg[i][1][1]=gg[i+1][1][1]+(a[i]==1);
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][a[i]][i][a[i]]=1;
	int j;
	for (int l=2;l<=n;l++){
		for (int i=1;(j=i+l-1)<=n;i++){
			f[i][0][j][0]=max(f[i+1][0][j][0],f[i][0][j-1][0]);
			f[i][1][j][0]=max(f[i+1][1][j][0],f[i][1][j-1][0]);
			f[i][1][j][1]=max(f[i+1][1][j][1],f[i][1][j-1][1]);
			if (a[i]==0){
				f[i][0][j][0]=max(f[i][0][j][0],f[i+1][0][j][0]+1);
			} else {
				f[i][1][j][0]=max(f[i][1][j][0],max(f[i+1][0][j][0],f[i+1][1][j][0])+1);
				f[i][1][j][1]=max(f[i][1][j][1],f[i+1][1][j][1]+1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
		for (int j=i-1;j;j-- )
			if(a[i]>=a[j])
				dp[i][0]=max(dp[i][0],dp[j][0]+1);
	}
	for(int i=n;i;i--){
		dp[i][1]=1;
		for(int j=i+1;j<=n;j++)
			if(a[i]<=a[j])
				dp[i][1]=max(dp[i][1],dp[j][1]+1);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			ans=max(ans,f[i][0][j][0]+gg[i-1][0][0]+dp[j+1][1]) ;
			ans=max(ans,f[i][1][j][0]+gg[i-1][0][0]+gg[j+1][1][1]) ;
			ans=max(ans,f[i][1][j][1]+dp[i-1][0]+gg[j+1][1][1]) ;
		}
	cout<<ans<<endl;
	return 0;
}
