#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
using namespace std;
long long n;
int a[]={5,1,3,4,2};
int k[]={1,1,6,-4,-4};
long long ans;
long long Pow(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)res=1LL*res*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<5;i++){
		ans+=1LL*k[i]*Pow(a[i],n)%mod;
		ans%=mod;
	}
	ans=((1LL*ans*Pow(4,mod-2)%mod)+mod)%mod;
	cout<<ans;
}
