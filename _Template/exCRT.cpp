#include<iostream>
#include<cstdio>
#define maxn 50010
using namespace std;
long long k,c[maxn],m[maxn];
long long qread(){
	long long i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
void exgcd(long long a,long long b,long long &d,long long &x,long long &y){
	if(!b)d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=x*(a/b);
}
long long inv(long long a,long long p){
	long long d,x,y;
	exgcd(a,p,d,x,y);
	return (x+p)%p==0?p:(x+p)%p;
}
long long gcd(long long a,long long b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	long long m1,m2,c1,c2;
	while(scanf("%lld",&k)!=EOF){
		for(int i=1;i<=k;i++)m[i]=qread(),c[i]=qread();
		for(int i=2;i<=k;i++){
			m1=m[i-1],m2=m[i],c1=c[i-1],c2=c[i];
			long long t=gcd(m1,m2);
			if((c2-c1)%t!=0){c[k]=-1;break;}
			m[i]=m1*m2/t;
			c[i]=inv(m1/t,m2/t)*((c2-c1)/t)%(m2/t)*m1+c1;
			c[i]=(c[i]%m[i]+m[i])%m[i];
		}
		printf("%lld\n",c[k]);
	}
	return 0;
}
