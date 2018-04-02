#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,ans,mn=1000000000,n1,m1;
long long gcd(long long x,long long y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	freopen("lcm.in","r",stdin);freopen("lcm.out","w",stdout);
//	freopen("Cola.txt","r",stdin);
	scanf("%d%d",&n,&m);
	if(n<m)swap(n,m);ans=n-m;
	n1=n;m1=m;
	while(n1>0&&m1>0){
		if(n1<m1)swap(n1,m1);
		int now=n1-m1;n1-=m1;
		long long ansnow=1LL*(now+n)/gcd(now+n,now+m)*(now+m);
		if(ansnow<mn){mn=ansnow;if(now!=0)ans=now;}
		if((now+n)%(now+m)==0){break;}
	}
	if(max(n,m)>1e8){cout<<ans;return 0;}
	for(int i=1;i<=max(n,m);i++){
		long long ansnow=1LL*(i+n)/gcd(i+n,i+m)*(i+m);
		if(ansnow<mn){mn=ansnow;ans=i;}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdin);
}
