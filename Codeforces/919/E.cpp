/*
	题解地址：http://codeforces.com/blog/entry/57462 
	然而英文题解看的稀里糊涂
	学姐讲过之后，概述一下吧：
		在mod p意义下，n的循环节是p，a^n的循环节是p-1，所以n*a^n的循环节是P*(p-1)
		因此枚举j为1->p-1，就可以得到所有的结果
		具体的
		j*a^j=b (mod p)
		j=b/(a^j) (mod p)
		剩下的代码上就很清楚了 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,p;
long long x,ans;
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1LL*res*x%p;
		x=1LL*x*x%p;
		y>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d%d",&a,&b,&p);
	cin>>x;
	a=Pow(a,p-2);
	int cur=1;
	for(int i=0;i<p-1;i++){//枚举j 
		int nd=1LL*b*cur%p;
		long long my=i;
		if(my==0)my+=p-1;
		int dif=(my-nd+p)%p;
		my+=1LL*dif*(p-1);
		if(my<=x)
			ans+=(x-my)/(1LL*p*(p-1))+1;
		cur=1LL*cur*a%p;
	}
	cout<<ans;
	return 0;
}
