#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
using namespace std;
int n,a[maxn],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++){
            int mn=0x7fffffff,mx=0;
            for(int i=l;i<=r;i++)mn=min(mn,a[i]);
            for(int i=l;i<=r;i++)mx=max(mx,a[i]^mn);
            ans=max(ans,mx*mn);
        }
    cout<<ans;
    return 0;
}
