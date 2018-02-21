#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 400010
using namespace std;
int n,a[maxn],b[maxn],cnt;
long long tr[maxn];
long long query(int x){
	long long res=0;
	while(x){
		res+=tr[x];
		x-=x&(-x);
	}
	return res;
}
void add(int x){
	while(x<=n){
		tr[x]++;
		x+=x&(-x);
	}
}
int main(){
	freopen("gloves.in","r",stdin);freopen("gloves.out","w",stdout);
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n*2;i++){
		scanf("%d",&x);
		if(!a[x])a[x]=++cnt;
		b[i]=a[x];
	}
	long long ans=0;
	for(int i=1;i<=n*2;i++){
		ans+=i-1-query(b[i]);
		add(b[i]);
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
