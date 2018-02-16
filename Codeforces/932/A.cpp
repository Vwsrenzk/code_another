#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10010
using namespace std;
int n;
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)cout<<s[i];
	for(int i=n;i>=1;i--)cout<<s[i];
	return 0;
}
