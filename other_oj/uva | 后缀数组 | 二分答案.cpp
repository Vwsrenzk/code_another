#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 140080
using namespace std;
int key[maxn],belong[maxn],str[maxn];
bool vis[120];
int sa[maxn],t[maxn],t2[maxn],c[maxn];
int ht[maxn],rk[maxn];
char s[1010];
void build(int *s,int n,int m){
	int *x=t,*y=t2;
	for(int i=0;i<m;i++)c[i]=0;
	for(int i=0;i<n;i++)c[x[i]=s[i]]++;
	for(int i=1;i<m;i++)c[i]+=c[i-1];
	for(int i=n-1;~i;i--)sa[--c[x[i]]]=i;
	for(int k=1;k<=n;k<<=1){
		int p=0;
		for(int i=n-k;i<n;i++)y[p++]=i;
		for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
		for(int i=0;i<m;i++)c[i]=0;
		for(int i=0;i<n;i++)c[x[y[i]]]++;
		for(int i=1;i<m;i++)c[i]+=c[i-1];
		for(int i=n-1;~i;i--)sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for(int i=1;i<n;i++){
			if((y[sa[i]]==y[sa[i-1]])&&((y[sa[i]+k]==y[sa[i-1]+k]&&sa[i]+k<n&&sa[i-1]+k<n)||(sa[i]+k>=n&&sa[i-1]+k>=n)))x[sa[i]]=p-1;
			else x[sa[i]]=p++;
		}
		if(p>=n)break;
		m=p;
	}
}
void getHeight(int *s,int n){
	int k=0;
	for(int i=0;i<n;i++)rk[sa[i]]=i;
	for(int i=0;i<n;i++){
		if(k)k--;
		int j=sa[rk[i]-1];
		while(s[i+k]==s[j+k])k++;
		ht[rk[i]]=k;
	}
}
bool check(int n,int len,int num){
	int cnt=0;
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	if(!vis[belong[sa[0]]]){
		cnt++;
		vis[belong[sa[0]]]=1;
	}
	for(int i=1;i<n;i++){
		if(ht[i]<len){
			cnt=0;
			memset(vis,0,sizeof(vis));
			vis[0]=1;
			if(!vis[belong[sa[i]]]){
				vis[belong[sa[i]]]=1;
				cnt++;
			}
		}
		else {
			if(!vis[belong[sa[i]]]){
				vis[belong[sa[i]]]=1;
				cnt++;
			}
		}
		if(cnt>=num)return 1;
	}
	return 0;
}
void print(int n,int len,int num){
	int cnt=0;
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	if(!vis[belong[sa[0]]])cnt++;
	vis[belong[sa[0]]]=1;
	for(int i=1;i<n;i++){
		if(ht[i]<len){
			if(cnt>=num){
				for(int j=sa[i-1];j<sa[i-1]+len;j++)
					printf("%c",str[j]-18);
				printf("\n");
			}
			cnt=0;
			memset(vis,0,sizeof(vis));
			vis[0]=1;
			if(!vis[belong[sa[i]]]){
				cnt++;
				vis[belong[sa[i]]]=1;
			}
		}
		if(!vis[belong[sa[i]]]){
			cnt++;
			vis[belong[sa[i]]]=1;
		}
	}
	if(cnt>=num){
		for(int i=sa[n-1];i<sa[n-1]+len;i++)
			printf("%c",str[i]-18);
		printf("\n");
	}
}
int main(){
	int n;bool flag=1;
	while(1){
		scanf("%d",&n);
		if(n==0)return 0;
		if(!flag)printf("\n");
		else flag=0;
		memset(belong,0,sizeof(belong));
		int pos=0,cat=1;
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			int len=strlen(s);
			r=max(r,len);
			for(int j=0;j<len;j++){
				str[pos+j]=(int)s[j]+18;
				belong[pos+j]=i;
			}
			str[pos+len]=cat++;
			pos=pos+len+1;
		}
		str[pos]=0;
		build(str,pos+1,150);getHeight(str,pos+1);
		int maxlen=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(pos+1,mid,n/2+1)){
				maxlen=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		if(maxlen==0)printf("?\n");
		else print(pos+1,maxlen,n/2+1);
	}
	return 0;
}
