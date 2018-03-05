#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)return 0;
		if(n&1)puts("ailyanlu");
		else puts("8600");
	}
}
