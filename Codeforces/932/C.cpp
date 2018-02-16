#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a,b,cnt;
void work(int x){
	int y=(n-a*x)/b;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=a;j++){
			if(j==1){printf("%d ",cnt+a);}
			else {
				cnt++;
				printf("%d ",cnt);
			}
		}
		cnt++;
	}
	for(int i=1;i<=y;i++){
		for(int j=1;j<=b;j++){
			if(j==1){printf("%d ",cnt+b);}
			else {
				cnt++;
				printf("%d ",cnt);
			}
		}
		cnt++;
	}
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(a>b)swap(a,b);
	for(int i=0;i<=a;i++){
		if((n-i*b)%a==0){work((n-i*b)/a);return 0;}
		else if(n-i*b<a)break;
	}
	puts("-1");return 0;
}
