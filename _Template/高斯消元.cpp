/*高斯消元求解线性方程组*/
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
#define N 100
#define eps (1e-8)
int n;double a[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)scanf("%lf",&a[i][j]);
    for(int i=1;i<=n;i++){
        int p=i;
        for(int j=i+1;j<=n;j++)if(fabs(a[j][i])>fabs(a[p][i]))p=j;
        for(int j=1;j<=n+1;j++)swap(a[p][j],a[i][j]);
        if(fabs(a[i][i])<eps)continue;
        double tmp=a[i][i];
        for(int j=1;j<=n+1;j++)a[i][j]/=tmp;
        for(int j=1;j<=n;j++)
            if(i!=j){
                double tmp=a[j][i];
                for(int k=1;k<=n+1;k++)a[j][k]-=a[i][k]*tmp;
            }
    }
    int imp=0,ult=0;
    for(int i=1;i<=n;i++){
        int j=1;
        while(fabs(a[i][j])<eps&&j<=n+1)j++;
        if(j>n+1)ult=1;
        else if(j==n+1)imp=1;
    }
    if(imp){printf("-1");return 0;}
    if(ult){printf("0");return 0;}
    for(int i=1;i<=n;i++){
        if(fabs(a[i][n+1])<eps)printf("x%d=0\n",i);
        else printf("x%d=%.2lf\n",i,a[i][n+1]);
    }
}
