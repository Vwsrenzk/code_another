#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000010
using namespace std;
char s[maxn];
int nxt[maxn],n;
void getnxt(){
	int i=0,j=-1;
	nxt[0]=-1;
	while(i!=n){
		if((j==-1)||(s[i]==s[j]))nxt[++i]=++j;
		else j=nxt[j];
	}
}
int main(){
	int Case=0;
	while(1){
		scanf("%d",&n);
		if(n==0)return 0;
		Case++;
		printf("Test case #%d\n",Case);
		scanf("%s",s);
		getnxt();
		for(int i=2;i<=n;i++)
			if((i%(i-nxt[i])==0)&&nxt[i])
				printf("%d %d\n",i,i/(i-nxt[i]));
		puts("");
	}
	return 0;
}
