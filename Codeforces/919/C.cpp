#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2010
using namespace std;
char ch[maxn][maxn];
int n,m,k,a[maxn][maxn],b[maxn][maxn];
void work1(){
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ch[i][j]=='.')cnt++;
	printf("%d",cnt);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(ch[i][j]=='.')a[i][j]=a[i][j-1]+1;
			else a[i][j]=0;
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			if(ch[j][i]=='.')b[j][i]=b[j-1][i]+1;
			else b[j][i]=0;
		}
	if(k==1){
		work1();
		return 0;
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]>=k)cnt++;
				if(b[i][j]>=k)cnt++;
			}
		}
		printf("%d",cnt);
		return 0;
	}
}
