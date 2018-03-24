#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#define maxn 100010
#define INF 1000000000
using namespace std;
double h1[maxn],h2[maxn];
int head[maxn],num,du[maxn],head2[maxn],num2,cnt,n;
struct node{int to,pre;}e[1000010],e2[maxn];
bool vis[maxn];
void Insert(int from,int to){
	e[++num].to=to;
	e[num].pre=head[from];
	head[from]=num;
}
void Insert2(int from,int to){
	e2[++num2].to=to;
	e2[num2].pre=head2[from];
	head2[from]=num2;
}
void bfs(int x){
	queue<int>q;
	q.push(x);vis[x]=1;
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			if(!vis[to]){
				vis[to]=1;
				q.push(to);
			}
		}
	}
}
int a[maxn],b[maxn];
double ans[maxn],g[110][110],f[maxn];
void Gauss(int n,int m){
	for(int i=1;i<m;i++){
		int k=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(g[j][i])>fabs(g[k][i]))k=j;
		if(i!=k)for(int j=1;j<=m;j++)swap(g[i][j],g[k][j]);
		for(int j=i+1;j<=n;j++){
			double t=g[j][i]/g[i][i];
			for(int k=i;k<=m;k++)
				g[j][k]-=g[i][k]*t;
		}
	}
	for(int i=m-1;i;i--){
		for(int j=i+1;j<m;j++)g[i][m]-=g[i][j]*ans[j];
		ans[i]=g[i][m]/g[i][i];
	}
}
void work1(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(h2[i]>=h1[j]){
				Insert(j,i);
				Insert2(i,j);
				du[i]++;
			}//倒着建边方便判断能否到达 
	for(int i=1;i<=n;i++)
		if(!du[i])Insert(n+1,i),Insert2(i,n+1),du[i]++;
	bfs(n+1);
	for(int i=1;i<=n;i++){
		if(!vis[i])f[i]=INF;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if((f[i]==INF)&&!vis[i])bfs(i);
	for(int i=1;i<=n;i++)
		if(vis[i])f[i]=INF;
	for(int i=1;i<=n;i++)
		if(f[i]!=INF){
			cnt++;
			b[i]=cnt;
			a[cnt]=i;
		}
	for(int i=1;i<=cnt;i++){
		for(int j=head2[a[i]];j;j=e2[j].pre){
			int to=b[e2[j].to];
			g[i][to]=-1.0;
		}
		g[i][cnt+1]=du[a[i]];
		g[i][i]+=du[a[i]];
	}
	/*for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt+1;j++){
			printf("%.4lf ",g[i][j]);
		}puts("");
	}*/
	Gauss(cnt,cnt+1);
	for(int i=1;i<=n;i++){
		if(f[i]==INF)printf("0.0000 ");
		else printf("%.4f ",ans[b[i]]);
	}
}
int p[maxn];
void work2(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(h2[i]>=h1[j]){
				Insert(j,i);
				du[i]++;
			}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(du[i]==0)q.push(i),f[i]=1,vis[i]=1;
		p[i]=du[i];
	}
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].pre){
			int to=e[i].to;
			du[to]--;
			f[to]+=f[now]/(double)p[to];
			if(du[to]==0&&!vis[to]){
				f[to]+=1;vis[to]=1;
				q.push(to);
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%.4lf ",f[i]);
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("jumping.in","r",stdin);freopen("jumping.out","w",stdout);
	scanf("%d",&n);
	double x;
	for(int i=1;i<=n;i++)scanf("%lf",&h1[i]);
	for(int i=1;i<=n;i++)scanf("%lf",&x),h2[i]=h1[i]-x;
	if(n<=100){
		work1();
		fclose(stdin);fclose(stdout);
		return 0;
	}
	work2();
	fclose(stdin);fclose(stdout);
	return 0;
}
