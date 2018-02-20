#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100010
using namespace std;
char s[maxn],c[maxn];
int n,tr[maxn][30],cnt,fail[maxn],b[maxn],sum,st[maxn],pos[maxn];
void Insert(){
	int now=0,l=strlen(c+1);
	for(int i=1;i<=l;i++){
		int t=c[i]-'a'+1;
		if(!tr[now][t])tr[now][t]=++cnt;
		now=tr[now][t];
	}
	b[now]=l;
}
queue<int>q;
void getfail(){
	for(int i=1;i<=26;i++)if(tr[0][i])q.push(tr[0][i]);
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=1;i<=26;i++){
			if(!tr[now][i])tr[now][i]=tr[fail[now]][i];
			else{
				q.push(tr[now][i]);
				fail[tr[now][i]]=tr[fail[now]][i];
			}
		}
	}
}
void getans(int l){
	int now=0;
	for(int i=1;i<=l;i++){
		int t=s[i]-'a'+1;
		now=tr[now][t];
		st[++sum]=now;pos[sum]=i;
		if(b[now]){
			sum-=b[now];
			now=st[sum];
		}
	}
}
int main(){
	scanf("%s",s+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",c+1),Insert();
	getfail();
	int l=strlen(s+1);getans(l);
	for(int i=1;i<=sum;i++)printf("%c",s[pos[i]]);
	return 0;
}
