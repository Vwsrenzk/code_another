#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt,ans[100010];
long long a,b,c,k;
long long Pow(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
int count(int x){
	int res=0;
	while(x){
		res+=x%10;
		x/=10;
	}
	return res;
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("safe.in","r",stdin);freopen("safe.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		cnt=0;
		cin>>a>>b>>c>>k;
		for(int i=0;i<=81;i++){
			long long x=Pow(i,a);
			x=x*b;
			x+=c;
			if(x<=k&&x>=0&&count(x)==i)ans[++cnt]=x;
		}
		printf("%d\n",cnt);
		if(cnt==0)puts("-1");
		else {
			sort(ans+1,ans+cnt+1);
			for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);puts("");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
