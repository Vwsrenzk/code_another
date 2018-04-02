#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 610
using namespace std;
int n,m,p,ans=1,f[maxn][maxn],s[maxn][maxn];
int k,num,head[maxn],rd[maxn],cd[maxn];
int l1,l2,s1[maxn],s2[maxn];
struct node{int to,pre;}e[100010];
void Insert(int from,int to){
	e[++num].to=to;
	e[num].pre=head[from];
	head[from]=num;
	cd[from]++;rd[to]++;
}
queue<int>q;
void dp(){
	for(int i=1;i<=n;i++){
		if(rd[i]==0)s1[++l1]=i,q.push(i),f[i][i]=1;
		if(cd[i]==0)s2[++l2]=i;
	}
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			rd[to]--;
			if(!rd[to])q.push(to);
			for(int j=1;j<=l1;j++)
				f[s1[j]][to]=(1LL*f[s1[j]][to]+1LL*f[s1[j]][now])%p;
		}
	}
}
void build(){
	for(int i=1;i<=l1;i++)
		for(int j=1;j<=l2;j++)
			s[i][j]=f[s1[i]][s2[j]];
}
void gauss(){
	int res=1;
	for(int i=1;i<=l1;i++){
		for(int j=i+1;j<=l1;j++){
			while(s[j][i]){
				int tmp=s[i][i]/s[j][i];
				for(int k=i;k<=l2;k++){
					s[i][k]=(s[i][k]-1LL*s[j][k]*tmp%p)%p;
					swap(s[i][k],s[j][k]);
				}
				res=-res;
			}
		}
		res=1LL*res*s[i][i]%p;
	}
	res=(res+p)%p;
	cout<<res<<endl;
}
int main(){
	freopen("orzcyr.in","r",stdin);freopen("orzcyr.out","w",stdout);
	int a,b;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		Insert(a,b);
	}
	dp();
	build();
	gauss();
	return 0;
}
