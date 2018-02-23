#include<iostream>
#include<cstdio>
#include<cmath>
#define lon long long
using namespace std;
int n,a,p;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d%d%d",&n,&a,&p);
	int A=sqrt(n),B=A*(n/A);
	lon ch=1,base=0;
	for(int i=1;i<=A;i++){
		base+=ch;base%=p;
		ch*=a;ch%=p;
	}
	lon x=1,ans=0;
	for(int i=1;i+A-1<=n;i+=A){
		ans+=base*x;ans%=p;
		x*=ch;x%=p;
	}
	for(int i=B+1;i<=n;i++){
		ans+=x;ans%=p;
		x*=a;x%=p;
	}
	cout<<ans;
	return 0;
}
