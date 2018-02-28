#include<iostream>
#include<cstdio>
#define maxn 4000010
using namespace std;
int n,cnt,m;
bool vis[maxn];
long long p[maxn],phi[maxn],f[maxn],g[maxn],ans[maxn];
void prepare(){
	phi[1]=1;
	for(int i=2;i<=4000000;i++){
		if(!vis[i])p[++cnt]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&i*p[j]<=4000000;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	for(int i=1;i<=4000000;i++)
		for(int j=i*2;j<=4000000;j+=i)
			f[j]+=phi[j/i]*i;
	ans[2]=f[2];
	for(int i=3;i<=4000000;i++)ans[i]=ans[i-1]+f[i];
}
int main(){
	prepare();
	while(1){
		scanf("%d",&n);m=n;
		if(n==0)return 0;
		cout<<ans[n]<<endl;
	}
	return 0;
}
