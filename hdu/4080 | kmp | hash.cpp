#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 40010
#define mod1 100007
#define mod2 1001117
using namespace std;
int h1[mod1+10],h2[mod1+10],f[maxn],g[maxn];
int m,pos,slen,a[mod1+10][2];
char s[maxn];
bool check(int len){
	if(len==0)return 1;
	memset(h1,-1,sizeof(h1));
	memset(h2,-1,sizeof(h2));
	memset(a,0,sizeof(a));
	int x=0,y=0,p1;
	for(int i=0;i<len;i++){
		x=(x*26+s[i])%mod1;
		y=(y*26+s[i])%mod2;
	}
	p1=x;
	while(!((h1[p1]==x&&h2[p1])||(h1[p1]==-1)))p1=(p1+1)%mod1;
	a[p1][0]=0;
	if(h1[p1]==-1)a[p1][1]=1;
	else a[p1][1]++;
	h1[p1]=x;
	h2[p1]=y;
	
	for(int i=len;i<slen;i++){
		x=(((x-s[i-len]*f[len])*26+s[i])%mod1+mod1)%mod1;
		y=(((y-s[i-len]*g[len])*26+s[i])%mod2+mod2)%mod2;
		p1=x;
		while(!((h1[p1]==x&&h2[p1]==y)||(h1[p1]==-1)))p1=(p1+1)%mod1;
		a[p1][0]=i-len+1;
		if(h1[p1]==-1)a[p1][1]=1;
		else a[p1][1]++;
		h1[p1]=x;
		h2[p1]=y;
	}
	bool flag=0;
	x=-1;
	for(int i=0;i<mod1;i++)
		if(h1[i]!=-1&&a[i][1]>=m){
			flag=1;
			x=max(x,a[i][0]);
		}
	if(!flag)return 0;
	pos=x;
	return 1;
}
void work(){
	slen=strlen(s);
	int l=0,r=slen;
	for(int i=0;i<slen;i++)s[i]=s[i]-'a';
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	check(ans);
	if(ans>0)printf("%d %d\n",ans,pos);
	else puts("none");
}
int main(){
	f[1]=g[1]=1;
	for(int i=2;i<=maxn-2;i++){
		f[i]=(f[i-1]*26)%mod1;
		g[i]=(g[i-1]*26)%mod2;
	}
	while(~scanf("%d",&m)){
		if(m==0)return 0;
		scanf("%s",s);
		work();
	}
}
