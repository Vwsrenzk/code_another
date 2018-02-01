#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
double a,b,mn=100000000;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&a,&b);
		mn=min(mn,a/b);
	}
	double ans=m*mn;
	printf("%.10lf",ans);
	return 0;
}
