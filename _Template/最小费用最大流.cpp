#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define INF 1e9
#define maxn 200010
using namespace std;
int n,m,s,t,dis[maxn],head[maxn],num=1,ans;
bool vis[maxn];
struct node{
    int to,pre,c,cc;
}e[maxn];
void Insert(int from,int to,int c,int cc){
    e[++num].to=to;e[num].c=c;e[num].cc=cc;
    e[num].pre=head[from];head[from]=num;
}
bool spfa(){
    deque<int>q;q.push_front(t);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[t]=0;vis[t]=1;
    while(!q.empty()){
        int now=q.front();q.pop_front();vis[now]=0;
        for(int i=head[now];i;i=e[i].pre){
            int to=e[i].to;
            if(e[i^1].c>0&&dis[to]>dis[now]-e[i].cc){
                dis[to]=dis[now]-e[i].cc;
                if(!vis[to]){
                    vis[to]=1;
                    if(!q.empty()&&dis[to]<dis[q.front()])q.push_front(to);
                    else q.push_back(to);
                }
            }
        }
    }
    return dis[s]<INF;
}
int dfs(int x,int flow){
    if(x==t){vis[t]=1;return flow;}
    int delta,rest=0;vis[x]=1;
    for(int i=head[x];i;i=e[i].pre){
        int to=e[i].to;
        if(e[i].c>0&&!vis[to]&&dis[to]==dis[x]-e[i].cc){
            delta=dfs(to,min(e[i].c,flow-rest));
            if(delta){
                e[i].c-=delta;e[i^1].c+=delta;
                rest+=delta;ans+=e[i].cc*delta;
                if(rest==flow)break;
            }
        }
    }
    return rest;
}
int costflow(){
    int flow=0;
    while(spfa()){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof(vis));
            flow+=dfs(s,INF);
        }
    }
    return flow;
}
int main(){
    freopen("Cola.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&s,&t);
    int x,y,c,cc;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&x,&y,&c,&cc);
        Insert(x,y,c,cc);Insert(y,x,0,-cc);
    }
    printf("%d ",costflow());printf("%d",ans);
}
