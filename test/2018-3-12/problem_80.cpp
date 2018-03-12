#include<iostream>
#include<cstdio>
using namespace std;
int f[1010][1010],n,p,k,r,fac[1000010];
void work1(){
	f[0][0]=1;
	for(int i=1;i<=n*k;i++){
		f[i][0]=f[i][i]=1;
		for(int j=1;j<i;j++)f[i][j]=(f[i-1][j-1]+f[i-1][j])%p;
	}
	int ans=0;
	for(int i=0;i*k+r<=n*k;i++){
		ans+=f[n*k][i*k+r];
		ans%=p;
	}
	printf("%d\n",ans);
}
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1LL*res*x%p;
		x=1LL*x*x%p;
		y>>=1;
	}
	return res;
}
int C(int n,int m){
	return 1LL*fac[n]*Pow(fac[m],p-2)%p*1LL*Pow(fac[n-m],p-2)%p;
}
void work2(){
	fac[0]=1;
	for(int i=1;i<=n*k;i++)fac[i]=1LL*fac[i-1]*i%p;
	long long ans=0;
	for(int i=0;i*k+r<=n*k;i++){
		ans+=C(n*k,i*k+r);
		ans%=p;
	}
	cout<<ans;
}
int Pow1(int x,long long y){
	int res=1;
	while(y){
		if(y&1)res=1LL*res*x%p;
		x=1LL*x*x%p;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("problem.in","r",stdin);freopen("problem.out","w",stdout);
//	freopen("Cola.txt","r",stdin);
	scanf("%d%d%d%d",&n,&p,&k,&r);
	if(p==2){cout<<0<<endl;return 0;}
	if(n<=30&&k<=30){work1();return 0;}
	if(k==1){printf("%d",Pow1(2,1LL*n*k));return 0;}
	if(k==2){printf("%d",Pow1(2,1LL*n*k-1));return 0;}
	work2();
}
