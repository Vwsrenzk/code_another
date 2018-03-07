#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 210
#define M 210*210*2
#define eps 0.0000001
#define INF 1000000000
using namespace std;
int n,head[maxn],num,S,T,cur[maxn];
double a[maxn][maxn],b[maxn][maxn],dis[maxn],ans;
int To[M],pre[M],v[M];
double cost[M];
bool vis[maxn];
void Insert(int from,int too,int vv,double costt){
    To[++num]=too;v[num]=vv;cost[num]=costt;pre[num]=head[from];head[from]=num;
    To[++num]=from;v[num]=0;cost[num]=-costt;pre[num]=head[too];head[too]=num;
}
double abs(double x){return x>0?x:-x;}
void build(double x){
    memset(head,0,sizeof(head));num=1;
    for(int i=1;i<=n;i++)Insert(S,i,1,0);
    for(int i=n+1;i<=n*2;i++)Insert(i,T,1,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            double v=x*b[i][j]-a[i][j];
            Insert(i,j+n,1,v);
        }
}
bool spfa(){
    queue<int>q;
    for(int i=S;i<=T;i++)dis[i]=INF,vis[i]=0,cur[i]=head[i];
    dis[S]=0;vis[S]=1;q.push(S);
    while(!q.empty()){
        int now=q.front();q.pop();vis[now]=0;
        for(int i=head[now];i;i=pre[i]){
            int to=To[i];
            if(v[i]>0&&dis[to]>dis[now]+cost[i]){
                dis[to]=dis[now]+cost[i];
                if(!vis[to]){vis[to]=1;q.push(to);}
            }
        }
    }
    return dis[T]!=INF;
}
int dinic(int x,int flow){
    if(x==T||flow==0)return flow;
    vis[x]=1;
    int rest=flow;
    for(int &i=cur[x];i;i=pre[i]){
        int to=To[i];
        if(!vis[to]&&(dis[to]==dis[x]+cost[i])&&(v[i]>0)){
            int delta=dinic(to,min(v[i],flow));
            v[i]-=delta;
            v[i^1]+=delta;
            ans+=delta*cost[i];
            rest-=delta;
            if(rest==0)break;
        }
    }
    vis[x]=0;
    return flow-rest;
}
bool check(){
    ans=0;
    while(spfa()){
        memset(vis,0,sizeof(vis));
        dinic(S,INF);
    }
    if(abs(ans)<eps||ans>0)return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    S=0,T=n*2+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&b[i][j]);
    double ans=0,l=0,r=10000000;
    while((r-l)>eps){
        double mid=(l+r)/2.0;
        build(mid);
        if(check())r=mid,ans=mid;
        else l=mid;
    }
    printf("%.6lf",ans);
    return 0;
}
