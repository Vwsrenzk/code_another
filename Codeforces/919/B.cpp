#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int k,cnt;
bool check(int x){
	int res=0;
	while(x){
		res+=x%10;
		x/=10;
	}
	return res==10;
}
int main(){
	scanf("%d",&k);
	for(int i=1;;i++){
		if(check(i))cnt++;
		if(cnt==k){
			printf("%d",i);
			return 0;
		}
	}
}
