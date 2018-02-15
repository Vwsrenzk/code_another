#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n>36){puts("-1");return 0;}
	if(n==0){
		puts("1");
		return 0;
	}
	if(n==1){
		puts("6");
		return 0;
	} 
	if(n&1){
		int x=n/2;
		for(int i=1;i<=x;i++)printf("8");
		printf("0");
		return 0;
	}
	else{
		int x=n/2;
		for(int i=1;i<=x;i++)printf("8");
		return 0;
	}
}
