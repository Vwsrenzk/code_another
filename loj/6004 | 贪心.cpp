#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300
using namespace std;
int n,m,sum1,sum2,belong[maxn][maxn],cnt[maxn];
struct node{int sz,id;}r[maxn],c[maxn];
bool cmp(node x,node y){return x.sz>y.sz;}
bool cmp1(node x,node y){return x.id>y.id;}
int main(){
	scanf("%d%d",&n,&m);//单位数、餐桌数 
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i].sz);
		sum1+=r[i].sz;
		if(r[i].sz>m){puts("0");return 0;}
		r[i].id=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i].sz);
		sum2+=c[i].sz;
		c[i].id=i;
	}
	if(sum1>sum2){puts("0");return 0;}
	sort(r+1,r+n+1,cmp);
	sort(c+1,c+m+1,cmp);
	for(int i=1;i<=m;i++){//枚举每张餐桌 
		for(int j=1;j<=n;j++){//枚举每个单位 
			if(r[j].sz>0&&c[i].sz>0){
				r[j].sz--;c[i].sz--;//将j单位的一个人放到i餐桌上 
				cnt[r[j].id]++;
				belong[r[j].id][cnt[r[j].id]]=c[i].id;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(r[i].sz!=0){puts("0");return 0;}
	sort(r+1,r+n+1,cmp1);
	puts("1");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			printf("%d ",belong[i][j]);
		}
		puts("");
	}
	return 0;
}
