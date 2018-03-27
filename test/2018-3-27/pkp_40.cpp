#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long l,r;
int k;
int count(int x){
	int res=0;
	while(x){
		res+=x%10;
		x/=10;
	}
	return res;
}
void work1(){
	int ans=0,sum=0;
	for(int i=l;i<=r;i++){
		sum+=count(i);
		if(sum>=k)ans++,sum=0;
	}
	printf("%d",ans);
}
int main(){
	freopen("pkp.in","r",stdin);freopen("pkp.out","w",stdout);
	cin>>l>>r;
	scanf("%d",&k);
	if(k==1){cout<<r-l+1;return 0;}
	if(r<=1e5){work1();return 0;}
	
}
