#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define maxn 160
using namespace std;
int val[maxn*maxn],tr[maxn*maxn][27],sz,fail[maxn*maxn],cnt[maxn];
char s[1000010],ch[maxn][100];
void Insert(int id){
	int n=strlen(ch[id]+1),now=0;
	for(int i=1;i<=n;i++){
		int tmp=ch[id][i]-'a'+1;
		if(!tr[now][tmp])tr[now][tmp]=++sz;
		now=tr[now][tmp];
	}
	val[now]=id;
}
void getfail(){
	queue<int>q;fail[0]=0;
	for(int i=1;i<=26;i++)
		if(tr[0][i]){
			q.push(tr[0][i]);
			fail[tr[0][i]]=0;
		}
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=1;i<=26;i++){
			int cur=tr[now][i];
			if(!cur)continue;
			q.push(cur);
			int to=fail[now];
			while(to&&!tr[to][i])to=fail[to];
			fail[cur]=tr[to][i];
		}
	}
}
void find(){
	int n=strlen(s+1);
	for(int i=1,j=0;i<=n;i++){
		int tmp=s[i]-'a'+1;
		while(j&&!tr[j][tmp])j=fail[j];
		j=tr[j][tmp];
		if(val[j])cnt[val[j]]++;
	}
}
int main(){
	int n;
	while(1){
		sz=0;
		memset(tr,0,sizeof(tr));
		memset(fail,0,sizeof(fail));
		memset(val,0,sizeof(val));
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		if(n==0)return 0;
		for(int i=1;i<=n;i++){
			scanf("%s",ch[i]+1);
			Insert(i);
		}
		getfail();
		scanf("%s",s+1);
		find();
		int mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,cnt[i]);
		printf("%d\n",mx);
		for(int i=1;i<=n;i++){
			if(cnt[i]==mx)printf("%s\n",ch[i]+1);
		}
	}
}
