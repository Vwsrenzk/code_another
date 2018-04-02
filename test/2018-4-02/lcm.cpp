#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
long long tmax, ans;
int A,B;
void check(int x){
	long long add=x-A%x;
	long long res=1LL*(A+add)/__gcd(A+add,B+add)*(B+add);
	if(res<tmax){
		tmax=res;
		ans=add;
	}
	else if(res==tmax)ans=min(ans,add);
}
int main(){
	freopen("lcm.in","r",stdin);freopen("lcm.out","w",stdout);
	scanf("%d%d",&A,&B);
	if(A==B){puts("1");return 0;}
	tmax=ans=INF;
	if(A>B)swap(A,B);
	int delt=B-A,lim=sqrt(delt);
	for(int i=1;i<=lim;i++)
		if(delt%i==0){
			check(i);
			check(delt/i);
		}
	cout<<ans<<endl;
	return 0;
}
