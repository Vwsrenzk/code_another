#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n%(m+1)==0)puts("second");
		else puts("first");
	}
	return 0;
}
