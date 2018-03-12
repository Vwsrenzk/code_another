#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;
long long A,B,C;
int n,m,t[maxn],b[maxn],a[maxn],c[maxn];
void work1(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(t[i]<b[m])
		ans+=C*(b[m]-t[i]);
	}
	cout<<ans;
}
void work2(){
	int mx=b[m];
	long long ans=0,w=0;
	for(int i=1;i<=n;i++){
		if(t[i]<b[m])
		ans+=C*(b[m]-t[i]);
	}
	while(w<ans){
		bool flag=0;
		b[1]++;b[m]--;w+=A;
		if(w>ans)break;
		if(b[1]>=b[m])flag=1;
		sort(b+1,b+m+1);
		long long nowans=0;
		for(int j=1;j<=n;j++){
			if(t[j]<b[m])
			nowans+=C*(b[m]-t[j]);
		}
		ans=min(ans,nowans+w);
	}
	cout<<ans;
}
void work3(){
	int mx=b[m];
	for(int i=1;i<=mx;i++){
		for(int j=1;j<=m;j++){
			if(b[j]>i)a[i]+=b[j]-i;
		}
		for(int j=1;j<=n;j++){
			if(t[j]<i)c[i]+=i-t[j];
		}
	}
	long long ans=0,w=0;
	for(int i=1;i<=n;i++){
		if(t[i]<b[m])
		ans+=C*(b[m]-t[i]);
	}
	for(int i=1;i<=mx;i++){
		ans=min(ans,C*c[i]+a[i]*B);
	}
	cout<<ans;
}
int main(){
	freopen("exam.in","r",stdin);freopen("exam.out","w",stdout);
//	freopen("Cola.txt","r",stdin);
	cin>>A>>B>>C;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(t+1,t+n+1);sort(b+1,b+m+1);
	if((A==1e9)&&(B==1e9)&&(C<=1e2)){work1();return 0;}
	if((A<=1e2)&&(C<=1e2)&&(B==1e9)){work2();return 0;}
	if((B<=A)&&(A<=1e2)&&(C<=1e2)){work3();return 0;}
}
