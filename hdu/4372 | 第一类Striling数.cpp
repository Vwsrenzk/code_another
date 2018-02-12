/*
	第一类stirling数S（n，m）表示的是n个数排成m个非空环排列的数目
	每个环排列中必然有一个是可以看见的，然后再对这m个环求组合数
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2010
#define mod 1000000007
#ifdef WIN32
#define PLL "%I64d"
#else
#define PLL "%lld"
#endif
using namespace std;
int c[maxn][maxn],str[maxn][maxn];
void prepare(){
	for(int i=1;i<=2000;i++){
		c[i][i]=c[i][0]=1;
		str[i][0]=0;str[i][i]=1;
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
			str[i][j]=(1LL*(i-1)*str[i-1][j]%mod+str[i-1][j-1])%mod;
		}
	}
}
int main(){
	int T;scanf("%d",&T);
	prepare();
	while(T--){
		int n,f,b;
		scanf("%d%d%d",&n,&f,&b);
		int ans=1LL*c[f+b-2][f-1]*str[n-1][f+b-2]%mod;
		printf("%d\n",ans);
	}
	return 0;
}
