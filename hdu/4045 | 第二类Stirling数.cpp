/*
	题目大意：
		有N个机器，每天选出R个机器，而且每两个机器的编号差要大于等于K，而且每天将R个机器最多分为M组工作，问最多有多少种方案。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 2010
using namespace std;
int c[maxn][maxn],str[maxn][maxn];
void prepare(){
	c[0][0]=str[0][0]=1;
	for(int i=1;i<=2000;i++){
		c[i][0]=c[i][i]=str[i][i]=1;
		str[i][0]=0;
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
			str[i][j]=(1LL*str[i-1][j]*j%mod+str[i-1][j-1])%mod;
		}
	}
}
int Min(int x,int y){return x<y?x:y;}
int main(){
	prepare();
	int n,r,k,m;
	while(scanf("%d%d%d%d",&n,&r,&k,&m)!=EOF){
		int sum=0;
		if(n-((r-1)*k+1)<0){puts("0");continue;}
		for(int i=1;i<=Min(r,m);i++)
			sum=(sum+str[r][i])%mod;
		int ans=1LL*c[n-((r-1)*k+1)+r][r]*sum%mod;
		printf("%d\n",ans);
	}
	return 0;
}
