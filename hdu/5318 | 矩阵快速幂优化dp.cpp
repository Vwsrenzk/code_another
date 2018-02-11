#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 55
using namespace std;
int n,m,a[100];
char s1[20],s2[20];
struct matrix{
	long long zu[maxn][maxn];
	matrix(){memset(zu,0,sizeof(zu));}
	matrix operator * (const matrix x)const{
		matrix res;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					res.zu[i][j]=(res.zu[i][j]+zu[i][k]*x.zu[k][j]%mod)%mod;
		return res;
	}
}w1,w2;
bool ok(int x,int y){
	sprintf(s1,"%d",x);
	sprintf(s2,"%d",y);
	int l1=strlen(s1),l2=strlen(s2);
	for(int i=l1-1,j=0;i>=0,j<l2;i--,j++)
		if((l1-i>=2)&&(string(s1+i,s1+l1)==string(s2,s2+j+1)))return 1;
	return 0;
}
matrix Pow(matrix x,int y){
	matrix res=w1;
	while(y){
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
long long getans(matrix x){
	long long res=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			res+=x.zu[i][j];
			if(res>=mod)res-=mod;
		}
	return res;
}
int main(){
	for(int i=0;i<=maxn;i++)w1.zu[i][i]=1;
	int T;scanf("%d",&T);
	while(T--){
		memset(w2.zu,0,sizeof(w2.zu));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(ok(a[i],a[j]))w2.zu[i][j]=1;
		matrix ans=Pow(w2,m-1);
		cout<<getans(ans)<<endl;
	}
	return 0;
}
