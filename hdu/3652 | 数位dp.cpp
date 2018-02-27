#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[20][20][20],bin[20],len,n;
int dfs(int pos,int type,int mod,bool limit){
	if(pos==0)return (mod==0)&&(type==2);
	if(!limit&&dp[pos][type][mod]!=-1)return dp[pos][type][mod];
	int end=limit?bin[pos]:9,res=0;
	for(int i=0;i<=end;i++){
		int x=type;
		if(type==0&&i==1)x=1;
		if(type==1&&i!=1)x=0;
		if(type==1&&i==3)x=2;
		res+=dfs(pos-1,x,(mod*10+i)%13,limit&&(i==end));
	}
	if(!limit)dp[pos][type][mod]=res;
	return res;
}
int solve(int x){
	len=0;
	while(x){
		bin[++len]=x%10;
		x/=10;
	}
	return dfs(len,0,0,1);
}
int main(){
	memset(dp,-1,sizeof(dp));
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",solve(n));
	}
	return 0;
}
