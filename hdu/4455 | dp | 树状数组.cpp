#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000010
using namespace std;
int n,tr[maxn],a[maxn],pos[maxn],last[maxn];
long long dp[maxn];
void add(int pos,int x){
	while(pos<=n){
		tr[pos]+=x;
		pos+=pos&(-pos);
	}
}
int query(int pos){
	int res=0;
	while(pos){
		res+=tr[pos];
		pos-=pos&(-pos);
	}
	return res;
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)return 0;
		memset(pos,-1,sizeof(pos));
		memset(dp,0,sizeof(dp));
		memset(tr,0,sizeof(tr));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(pos[a[i]]!=-1){
				add(i-pos[a[i]]+1,1);
				add(i+1,-1);
			}
			pos[a[i]]=i;
		}
		memset(pos,-1,sizeof(pos));
		memset(last,0,sizeof(last));
		for(int i=n;i>=1;i--){
			last[n-i+1]=last[n-i];
			if(pos[a[i]]==-1)last[n-i+1]++;
			pos[a[i]]=i;
		}
		dp[1]=n;
		for(int i=2;i<=n;i++){
			dp[i]=dp[i-1]+n-i+1-query(i)-last[i-1];
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int x;scanf("%d",&x);
			printf("%I64d\n",dp[x]);
		}
	}
}
