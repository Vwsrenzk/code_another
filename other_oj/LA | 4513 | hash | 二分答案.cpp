#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 40010
using namespace std;
unsigned long long h[maxn],base[maxn];
int n,m,pos;
char s[maxn];
struct node{
	unsigned long long v;
	int id;
	bool operator < (const node x)const{
		return (v<x.v)||((v==x.v)&&(id<x.id));
	}
}Hash[maxn];
bool check(int L){
	int cnt=0;pos=-1;
	for(int i=0;i<n-L+1;i++){
		Hash[i].v=h[i]-h[i+L]*base[L];
		Hash[i].id=i;
	}
	sort(Hash,Hash+n-L+1);
	for(int i=0;i<n-L+1;i++){
		if(i==0||Hash[i].v!=Hash[i-1].v)cnt=0;
		cnt++;
		if(cnt>=m)
			pos=max(pos,Hash[i].id);
	}
	return pos>=0;
}
int main(){
	base[0]=1;
	for(int i=1;i<=40000;i++)base[i]=base[i-1]*123;
	while(1){
		scanf("%d",&m);
		if(m==0)return 0;
		scanf("%s",s);n=strlen(s);
		h[n]=0;
		for(int i=n-1;i>=0;i--)
			h[i]=h[i+1]*123+s[i]-'a';
		if(!check(1))puts("none");
		else{
			int l=1,r=n+1,ans=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(mid))l=mid+1,ans=mid;
				else r=mid-1;
			}
			check(ans);
			printf("%d %d\n",ans,pos);
		}
	}
}
