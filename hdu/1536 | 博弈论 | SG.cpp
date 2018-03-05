#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010
using namespace std;
int SG[maxn],S[maxn],k,m,sum,n;
int getSG(int x){
	bool flag[110]={0};
	for(int i=1;i<=k;i++){
		if(S[i]>x)break;
		int tmp=x-S[i];
		if(SG[tmp]==-1)SG[tmp]=getSG(tmp);
		flag[SG[tmp]]=1;
	}
	for(int i=0;;i++)if(!flag[i])return i;
}
int main(){
	while(1){
		scanf("%d",&k);
		if(k==0)return 0;
		memset(SG,-1,sizeof(SG));
		for(int i=1;i<=k;i++)scanf("%d",&S[i]);
		sort(S+1,S+k+1);
		scanf("%d",&m);
		int x;
		for(int i=1;i<=m;i++){
			sum=0;
			scanf("%d",&n);
			for(int j=1;j<=n;j++){
				scanf("%d",&x);
				if(SG[x]==-1)SG[x]=getSG(x);
				sum^=SG[x];
			}
			if(sum==0)printf("L");
			else printf("W");
		}
		puts("");
	}
	return 0;
}
