#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 2e18
#define maxn 100
using namespace std;
long long a[maxn],b[maxn],ans=INF;
long long qread(){
	long long i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=qread();
	for(int i=1;i<=m;i++)b[i]=qread();
	for(int i=1;i<=n;i++){
		long long cur=-INF;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			for(int k=1;k<=m;k++)cur=max(cur,a[j]*b[k]);
		}
		ans=min(ans,cur);
	}
	cout<<ans;
}
