#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 20
#define mod 1000000007
using namespace std;
struct matrix{
	long long zu[maxn][maxn];
	matrix(){memset(zu,0,sizeof(zu));}
};
long long qread(){
	long long i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
matrix mul(matrix x,matrix y,int n){
	matrix res;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				res.zu[i][j]=(res.zu[i][j]+x.zu[i][k]*y.zu[k][j]%mod)%mod;
	return res;
}
matrix Pow(matrix x,long long y,int z){
	matrix res;
	for(int i=0;i<=z;i++)res.zu[i][i]=1;
	while(y){
		if(y&1)res=mul(res,x,z);
		x=mul(x,x,z);
		y>>=1;
	}
	return res;
}
int main(){
	int n;long long k;
	matrix a;
	for(int i=0;i<=16;i++)
		for(int j=i-1;j<=i+1;j++)
			if(j<=16&&j>=0)a.zu[i][j]=1;
	while(scanf("%d",&n)!=EOF){
		k=qread();
		long long dp1[maxn],dp2[maxn];
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		dp2[0]=1;
		for(int i=0;i<n;i++){
			long long x=qread(),y=qread(),z=qread();
			if(i==n-1)y=k;
			memset(dp1,0,sizeof(dp1));
			for(int i1=0;i1<=z;i1++)dp1[i1]=dp2[i1];
			memset(dp2,0,sizeof(dp2));
			matrix ans=Pow(a,y-x,z);
			for(int i1=0;i1<=z;i1++)
				for(int j=0;j<=z;j++)
					dp2[i1]=(dp2[i1]+dp1[j]%mod*ans.zu[i1][j]%mod)%mod;
		}
		cout<<dp2[0]<<endl;
	}
}
