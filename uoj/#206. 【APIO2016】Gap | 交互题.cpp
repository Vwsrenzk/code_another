#include"gap.h"
#include<iostream>
using namespace std;
long long findGap(int T, int N){
	long long a,b,c,d,ans=0,L;
	if(T==1){
		MinMax(0,1000000000000000000LL,&a,&b);
		for(int cnt=2;cnt*2<=N+1;cnt++){
			MinMax(a+1,b-1,&c,&d);
			ans=max(ans,max(c-a,b-d));
			a=c,b=d;
		}
		return max(ans,b-a);
	}
	else{
		MinMax(0,1000000000000000000LL,&a,&b);
		L=(b-a)/(N-1);
		if((N-1)*L<b-a)L++;
		ans=L;
		long long tmp=a;
		while(tmp<b){
			MinMax(tmp,tmp+L-1,&c,&d);
			if(c!=-1){
				ans=max(ans,c-a);
				a=d;
			}
			tmp+=L;
		}
		ans=max(ans,b-a);
		return ans;
	}
}
