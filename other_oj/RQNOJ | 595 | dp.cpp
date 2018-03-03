#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 10010
#define INF 10000000000000000LL
using namespace std;
int n,m,a[maxn];
long long f[maxn][2][2],ans=INF;
long long sqr(long long x){
	return x*x;
}
void dp(){
	f[0][1][1]=f[0][0][1]=INF;
	for(int i=1;i<=n;i++)
		for(int j=0;j<2;j++)
			if((a[i]<a[i-1])^j){
                f[i][j][0]=f[i-1][j][0]+abs(a[i]-a[i-1]);
                f[i][j][1]=min(f[i-1][j][1],
                           min(f[i-1][j^1][0],f[i-1][j^1][1])+m)+abs(a[i]-a[i-1]);
            }
            else {
                f[i][j][0]=f[i-1][j][0]+sqr(a[i]-a[i-1]);
                f[i][j][1]=min(f[i-1][j][1],
                           min(f[i-1][j^1][0],f[i-1][j^1][1])+m)+sqr(a[i]-a[i-1]);
            }
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);a[n]=a[0];
	dp();
	ans=min(min(f[n][1][0],f[n][1][1]),min(f[n][0][0],f[n][0][1]));
	
	memset(f,0,sizeof(f));
	f[0][0][0]=INF;
	dp();
	ans=min(ans,f[n][1][1]-m);
	
	memset(f,0,sizeof(f));
	f[0][1][0]=INF;
	dp();
	ans=min(ans,f[n][0][1]-m);
	
	cout<<ans;
	return 0;
}
