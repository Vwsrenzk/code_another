#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 40010
using namespace std;
int n,p[maxn],cnt,phi[maxn];
bool vis[maxn];
long long ans;
void prepare(){
	phi[1]=1;
	for(int i=2;i<=40000;i++){
		if(!vis[i])p[++cnt]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&i*p[j]<=40000;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}
int main(){
	prepare();
	scanf("%d",&n);
	ans=1;if(n==1)ans=0;
	for(int i=1;i<n;i++)ans+=phi[i]*2;
	cout<<ans;
}
