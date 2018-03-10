#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 110
using namespace std;
long long b[100];
int n;
int main(){
	scanf("%d",&n);
	long long x;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=62;j>=0;j--)
			if((x>>j)&1){
				if(b[j])x^=b[j];
				else {
					b[j]=x;
					for(int k=j-1;k>=0;k--)
						if(((b[j]>>k)&1)&&b[k])b[j]^=b[k];
					for(int k=j+1;k<=62;k++)
						if(((b[k]>>j)&1))b[k]^=b[j];
					break;
				}
			}
	}
	long long ans=0;
	for(int i=0;i<=62;i++)ans^=b[i];
	cout<<ans;
	return 0;
}
