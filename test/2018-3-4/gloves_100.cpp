#include<iostream>
#include<cstdio>
#define maxn 400010
using namespace std;
int n,a[maxn],belong[maxn];
long long tr[maxn*4];
bool vis[maxn];
long long query(int x){
	long long res=0;
	while(x){
		res+=tr[x];
		x-=(x&-x);
	}
	return res;
}
void add(int x){
	while(x<=n){
		tr[x]++;
		x+=(x&-x);
	}
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("gloves.in","r",stdin);freopen("gloves.out","w",stdout);
	int cnt=0,x;
	scanf("%d",&n);n*=2;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(!vis[x]){
			belong[x]=++cnt;
			a[i]=belong[x];
			vis[x]=1;
		}
		else a[i]=belong[x];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=i-1-query(a[i]);
		add(a[i]);
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
