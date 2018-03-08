#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1010][1010],cnt[1010],mx;
long long sum[1010][1010];
int main(){
	scanf("%d%d",&n,&m);
	int s,t,w;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s,&t,&w);
		for(int j=s;j<=t;j++)//枚举这个任务的所有时刻 
			a[j][++cnt[j]]=w;
	}
	for(int i=1;i<=n;i++)sort(a[i]+1,a[i]+cnt[i]+1);
	int x,A,b,c,k;
	for(int i=1;i<=n;i++)//枚举每个时刻 
		for(int j=1;j<=cnt[i];j++)//枚举这个时刻内所有的优先级 
			sum[i][j]=sum[i][j-1]+a[i][j];
	long long pre=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&x,&A,&b,&c);
		k=1+(1LL*A*pre+b)%c;
		if(k>=cnt[x])k=cnt[x];
		pre=sum[x][k];
		printf("%lld\n",pre);
	}
	return 0;
}
