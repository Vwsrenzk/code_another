#include<iostream>
#include<cstdio>
using namespace std;
int f[1010][1010],n,p,k,r;
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
int main(){
	freopen("problem.in","r",stdin);freopen("problem.out","w",stdout);
//	freopen("Cola.txt","r",stdin);
	scanf("%d%d%d%d",&n,&p,&k,&r);
	if(p==2){cout<<0<<endl;return 0;}
	if(n<=30&&k<=30){work1();return 0;}
}
