#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long p;
int k;
int ans[10000000],cnt;
long long qread(){
	long long i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
int main(){
	p=qread();
	scanf("%d",&k);
	while(p!=0){
		int cur=(p%k+k)%k;
		ans[++cnt]=cur;
		p-=cur;p/=k;
		p=-p;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)cout<<ans[i]<<' ';
	return 0;
}
