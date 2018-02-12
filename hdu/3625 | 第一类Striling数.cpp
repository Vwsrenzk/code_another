#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 22
using namespace std;
long long str[maxn][maxn],ans[maxn];
void prepare(){
	for(int i=1;i<=20;i++){
		str[i][0]=0;str[i][i]=1;
		for(int j=1;j<i;j++)
			str[i][j]=(i-1)*str[i-1][j]+str[i-1][j-1];
	}
	ans[0]=ans[1]=1;
	for(int i=2;i<=20;i++)ans[i]=ans[i-1]*i;
}
int main(){
	prepare();
	int T;scanf("%d",&T);
	int n,m;
	while(T--){
		scanf("%d%d",&n,&m);
		long long sum=0;
		for(int i=1;i<=m;i++)sum+=str[n][i]-str[n-1][i-1];
		printf("%.4lf\n",(double)sum/(double)ans[n]);
	}
	return 0;
}
