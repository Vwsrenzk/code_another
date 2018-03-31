#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010
using namespace std;
int du[maxn],sp[maxn],type[maxn],head[maxn][2],num,sqr;
long long ans[3],sum[maxn][2];
struct node{int to,pre;long long w;}e[maxn*2];
struct Node{
	int u,v;long long w;
	bool operator < (const Node &b)const{
		if(u==b.u)return v<b.v;
		return u<b.u;
	}
	bool operator == (const Node &b)const{
		return u==b.u&&v==b.v;
	}
}E[maxn];
void Insert(int t,int from,int to,long long z){
	e[++num].to=to;
	e[num].w=z;
	e[num].pre=head[from][t];
	head[from][t]=num;
}
int main(){
	int Case=0,n,m,x;
	while(scanf("%d%d",&n,&m)!=EOF){
		printf("Case %d:\n",Case);
		for(int i=1;i<=n;i++)scanf("%d",&x),type[i]=x;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&E[i].u,&E[i].v);cin>>E[i].w;
			if(E[i].u>E[i].v)swap(E[i].u,E[i].v);
		}
		sort(E+1,E+m+1);
		int cnt=0;
		for(int i=1,j;i<=m;i++){
			for(j=i+1;j<m&&E[i]==E[j];j++)
				E[i].w+=E[j].w;
			E[++cnt]=E[i];
		}
		sqr=(int)sqrt(cnt<<1);
		memset(du,0,sizeof(du));
		for(int i=1;i<=cnt;i++)du[E[i].u]++,du[E[i].v]++;
		for(int i=1;i<=n;i++)sp[i]=(du[i]>=sqr);
		memset(head,0,sizeof(head));num=0;
		for(int i=1;i<=cnt;i++){
			int x=E[i].u,y=E[i].v;long long w=E[i].w;
			if(sp[x])Insert(1,y,x,w);else Insert(0,x,y,w);
			if(sp[y])Insert(1,x,y,w);else Insert(0,y,x,w);
		}
		memset(ans,0,sizeof(ans));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=cnt;i++){
			int x=E[i].u,y=E[i].v;long long w=E[i].w;
			if(sp[x])sum[x][type[y]]+=w;
			if(sp[y])sum[y][type[x]]+=w;
			ans[type[x]+type[y]]+=w;
		}
		int q,a,b,x;char s[20];
		scanf("%d",&q);
		while(q--){
			scanf("%s",s);
			if(s[0]=='A'){
				scanf("%d%d",&a,&b);
				cout<<ans[a+b]<<endl;
			}
			else{
				scanf("%d",&x);
				type[x]^=1;
				if(sp[x]){
					for(int i=0;i<=1;i++){
						ans[(type[x]^1)+i]-=sum[x][i];
						ans[type[x]+i]+=sum[x][i];
					}
				}
				else {
					for(int i=head[x][0];i;i=e[i].pre){
						int to=e[i].to;
						ans[(type[x]^1)+type[to]]-=e[i].w;
						ans[type[x]+type[to]]+=e[i].w;
					}
				}
				for(int i=head[x][1];i;i=e[i].pre){
					int to=e[i].to;
					sum[to][type[x]^1]-=e[i].w;
					sum[to][type[x]]+=e[i].w;
				}
			}
		}
	}
	return 0;
}
/*
N个点M条边的图
每个点有颜色
总共两种颜色
两种操作
修改某点颜色
询问某种边的条数
N<=100000 M<=100000

按度数将点分类
对于修改：修改小点直接暴力
修改大点直接将其与另外大点的信息重做
对于询问：每次暴力重做大点与小点的信息

*/
