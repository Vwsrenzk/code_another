#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 110
using namespace std;
int a[maxn],sum,n;
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)return 0;
		sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum^=a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if((sum^a[i])<a[i])ans++;
		printf("%d\n",ans);
	}
	return 0;
}
