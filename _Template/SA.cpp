include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 15010
using namespace std;
int m=26,n,sa[maxn],rank[maxn],c[maxn],s[maxn],x[maxn],y[maxn];
char ch[maxn];
int main(){
    freopen("Cola.txt","r",stdin);
    scanf("%d%s",&n,ch);
    for(int i=0;i<n;i++)s[i]=ch[i]-'a';
    
    for(int i=0;i<n;i++)c[x[i]=s[i]]++;
    for(int i=1;i<m;i++)c[i]+=c[i-1];
    for(int i=n-1;i!=-1;i--)sa[--c[x[i]]]=i;
    int k=1,p=0;
    while(k<=n){
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
        for(int i=0;i<m;i++)c[i]=0;
        for(int i=0;i<n;i++)c[x[y[i]]]++;
        for(int i=1;i<m;i++)c[i]+=c[i-1];
        for(int i=n-1;i!=-1;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);p=1;x[sa[0]]=0;
        for(int i=1;i<n;i++)
            if(y[sa[i-1]]==y[sa[i]]&&((y[sa[i-1]+k]==y[sa[i]+k]&&sa[i-1]+k<n&&sa[i]+k<n)||(sa[i-1]+k>=n&&sa[i]+k>=n))) x[sa[i]]=p-1;
            else x[sa[i]]=p++;
        if(p>=n)break;
        m=p;p=0;k*=2;
    }
    for(int i=0;i<n;i++)printf("%d\n",sa[i]+1);
}
