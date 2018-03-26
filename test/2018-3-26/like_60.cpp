#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
using namespace std;
int n,k,f[1010][1010];
int solve(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=(f[i][j]+mod)%mod;
	int res=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			while(f[j][i]){
				int t=-f[i][i]/f[j][i];
				for(int k=i;k<=n;k++)f[i][k]=(f[i][k]+1LL*t*f[j][k]%mod)%mod;
				for(int k=i;k<=n;k++)swap(f[i][k],f[j][k]);
				res=-res;
			}
		}
		if(f[i][i]==0)return 0;
		res=1LL*res*f[i][i]%mod;res%=mod;
	}
	res=(res+mod)%mod;
	return res;
}
int abs(int x){return x>0?x:-x;}
int main(){//度数矩阵-邻接矩阵 
//	freopen("Cola.txt","r",stdin);
	freopen("like.in","r",stdin);freopen("like.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1||n==1){puts("1");return 0;}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			if(abs(i-j)<=k){
				f[i][i]++;
				f[j][j]++;
				f[i][j]--;f[j][i]--;
			}
	}
	n--;
	printf("%d\n",solve());
	fclose(stdin);fclose(stdout);
	return 0;
}
