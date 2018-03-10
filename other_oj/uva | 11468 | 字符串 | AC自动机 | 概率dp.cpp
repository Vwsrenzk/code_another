#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 21*21
#define ran 63
using namespace std;
int tr[maxn][ran+1],fail[maxn],sz,n;
bool val[maxn],vis[maxn][maxn];
double dp[maxn][maxn],p[maxn];
char s[maxn],ch[maxn];
void init(){
	sz=1;
	memset(tr,0,sizeof(tr));
	memset(val,0,sizeof(val));
	memset(fail,0,sizeof(fail));
	memset(vis,0,sizeof(vis));
}
int get(char c){
	if(c<='9'&&c>='0')return c-'0';
	if(c<='Z'&&c>='A')return c-'A'+10;
	if(c<='z'&&c>='a')return c-'a'+36;
}
void Insert(){
	int len=strlen(s),now=1;
	for(int i=0;i<len;i++){
		int tmp=get(s[i]);
		if(!tr[now][tmp])tr[now][tmp]=++sz;
		now=tr[now][tmp];
	}
	val[now]=1;
}
void getfail(){
	queue<int>q;
	for(int i=0;i<ran;i++)tr[0][i]=1;
	q.push(1);
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=0;i<ran;i++){
			if(!tr[now][i]){
				tr[now][i]=tr[fail[now]][i];
				continue;
			}
			q.push(tr[now][i]);
			int to=fail[now];
			fail[tr[now][i]]=tr[to][i];
			if(val[tr[to][i]])val[tr[now][i]]=1;
		}
	}
}
double dfs(int now,int L){
	if(L==0)return 1.0;
	if(vis[now][L])return dp[now][L];
	vis[now][L]=1;
	double ans=0;
	for(int i=1;i<=n;i++){
		int tmp=get(s[i]);
		if(!val[tr[now][tmp]])ans+=p[i]*dfs(tr[now][tmp],L-1);
	}
	return dp[now][L]=ans;
}
int main(){
	int T;scanf("%d",&T);
	int Case=0;
	while(T--){
		Case++;
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			Insert();
		}
		getfail();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>s[i];
			scanf("%lf",&p[i]);
		}
		int L;
		scanf("%d",&L);
		printf("Case #%d: %.6lf\n",Case,dfs(1,L));
	}
	return 0;
}
