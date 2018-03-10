#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1010
using namespace std;
int n,m,l,r,tot,ct[maxn][maxn],nt[110];
char s[maxn][maxn],ss[maxn];
struct node{
	int fail,mark;
	int son[30];
}t[maxn*maxn];
void read_trie(int tk){
	scanf("%s",s[0]+1);
	int len=strlen(s[0]+1);
	for(int i=1;i<=len;i++)ss[i]=s[0][len-i+1];
	int now=0;
	for(int i=1;i<=len;i++){
		int id=ss[i]-'a'+1;
		if(!t[now].son[id]){
			t[now].son[id]=++tot;
			t[tot].mark=0;
			memset(t[tot].son,0,sizeof(t[tot].son));
		}
		now=t[now].son[id];
		if(i==len){
			if(t[now].mark)nt[tk]=t[now].mark;
			t[now].mark=tk;
		}
	}
}
queue<int>q;
void build_AC(){
	while(!q.empty())q.pop();
	q.push(0);
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=1;i<=26;i++){
			if(t[now].son[i]){
				t[t[now].son[i]].fail=now?t[t[now].fail].son[i]:0;
				q.push(t[now].son[i]);
			}
			else t[now].son[i]=t[t[now].fail].son[i];
		}
		if(t[t[now].fail].mark)t[now].mark=t[t[now].fail].mark;
	}
}
void add(int x,int y,int z){
	if(x-z+1>=1)ct[x-z+1][y]++;
	if(nt[z]!=0)add(x,y,nt[z]);
}
void find(){
	int now;
	memset(ct,0,sizeof(ct));
	for(int i=1;i<=n;i++){
		now=0;
		for(int j=m;j>=1;j--){
			now=t[now].son[s[i][j]-'a'+1];
			if(t[now].mark)add(i,j,t[now].mark);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(ct[i][j]==l)ans++;
	printf("%d\n",ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);//矩阵T 
		tot=0;
		t[0].mark=0;
		memset(t[0].son,0,sizeof(t[0].son));
		scanf("%d%d",&l,&r);
		memset(nt,0,sizeof(nt));
		for(int i=1;i<=l;i++)read_trie(i);//矩阵P 
		build_AC();
		find();
	}
	return 0;
}
