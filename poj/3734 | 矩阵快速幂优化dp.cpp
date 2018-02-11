#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 4
#define mod 10007
using namespace std;
struct matrix{
	int zu[maxn][maxn];
	matrix(){memset(zu,0,sizeof(zu));}
	matrix operator * (const matrix x)const{
		matrix res;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				for(int k=1;k<=3;k++)
					res.zu[i][j]=(res.zu[i][j]+zu[i][k]*x.zu[k][j]%mod)%mod;
		return res;
	}
}a;
matrix Pow(matrix x,int y){
	matrix res=x;y--;
	while(y){
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		matrix a;
		a.zu[1][1]=2;a.zu[1][2]=1;a.zu[1][3]=0;
		a.zu[2][1]=2;a.zu[2][2]=2;a.zu[2][3]=2;
		a.zu[3][1]=0;a.zu[3][2]=1;a.zu[3][3]=2;
		a=Pow(a,n);
		printf("%d\n",a.zu[1][1]);
	}
}
