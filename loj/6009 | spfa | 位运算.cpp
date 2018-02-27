#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define maxn 1148576
#define INF 1000000000
using namespace std;
int n,m,dis[maxn],t[maxn];
char s1[110][30],s2[110][30];
bool vis[maxn];
queue<int>q;
bool pd(int x,int k){
	for(int i=1;i<=n;i++){
		if((s1[k][i]=='+')&&(!(x&(1<<i-1))))return 0;
		if((s1[k][i]=='-')&&(x&(1<<i-1)))return 0;
	}
	return 1;
}
int findto(int x,int k){
	int res=0;
	for(int i=1;i<=n;i++){
		if(s2[k][i]=='-')res+=0;
		if(s2[k][i]=='+')res+=(1<<i-1);
		if(s2[k][i]=='0')res+=(x&(1<<i-1));
	}
	return res;
}
void spfa(){
	memset(dis,0x3f,sizeof(dis));
	dis[(1<<n)-1]=0;vis[(1<<n)-1]=1;q.push((1<<n)-1);
	while(!q.empty()){
		int now=q.front();q.pop();vis[now]=0;
		for(int i=1;i<=m;i++){
			if(pd(now,i)){
				int to=findto(now,i);
				if(dis[to]>dis[now]+t[i]){
					dis[to]=dis[now]+t[i];
					if(!vis[to]){vis[to]=1;q.push(to);}
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);//n个错误，m个补丁 
	for(int i=1;i<=m;i++)
		scanf("%d%s%s",&t[i],s1[i]+1,s2[i]+1);
	spfa();
	if(dis[0]<INF)printf("%d",dis[0]);
	else printf("0");
	return 0;
}
