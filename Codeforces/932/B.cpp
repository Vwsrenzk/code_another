#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int sum[1000010][20];
int f(int x){
	int now=1;
	while(x){
		int y=x%10;
		if(y!=0)now*=y;
		x/=10;
	}
	return now;
}
int g(int x){
	if(x<10)return x;
	return g(f(x));
}
void prepare(){
	for(int i=1;i<=1000000;i++){
		for(int j=0;j<10;j++)sum[i][j]=sum[i-1][j];
		int now=g(i);
		sum[i][now]++;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	prepare();
	int x,y,z;
	while(T--){
		scanf("%d%d%d",&x,&y,&z);
		printf("%d\n",sum[y][z]-sum[x-1][z]);
	}
	return 0;
}
