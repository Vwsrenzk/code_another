#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000
#define maxn 2010
using namespace std;
int str[maxn][maxn],b[maxn];
void prepare(){
	b[1]=1;str[1][1]=1;
	for(int i=2;i<=2000;i++){
		for(int j=1;j<=i;j++){
			str[i][j]=(j*str[i-1][j]%mod+str[i-1][j-1])%mod;
			b[i]+=str[i][j];
		}
		b[i]%=mod;
	}
}
int main(){
	prepare();
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		int ans=0;
		printf("%d\n",b[n]);
	}
	return 0;
}
