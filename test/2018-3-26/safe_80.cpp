#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,c,k,cnt,ans[100010],f[1000010];
int count(int x){
	int res=0;
	while(x){
		res+=x%10;
		x/=10;
	}
	return res;
}
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
void work1(){
	cnt=0;
	for(int i=0;i<=k;i++){
		int res=Pow(f[i],a)*b+c;
		if(res==i)ans[++cnt]=i;
	}
	if(!cnt){puts("0");puts("-1");return;}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);puts("");
}
void work2(){
	int limit=min(k,81*b);
	cnt=0;
	for(int i=0;i<=limit;i+=b){
		if(f[i]*b==i)ans[++cnt]=i;
	}
	if(!cnt){puts("-1");return;}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);puts("");
}
int Sqrt(int x,int y){
	for(int i=1;i<=10000;i++)
		if(Pow(i,y)>=x)return i;
	return 1000000000;
}
long long lPow(long long x,int y){
	long long res=1;
	while(y){
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
void work3(){
	int limit=min(lPow(81,a),(long long)k);
	cnt=0;
	for(int i=0;i<=limit;i++){
		long long j=lPow(i,a);
		if(j>(long long)k)break;
		if(count(j)==i)ans[++cnt]=j;
	}
	if(!cnt){puts("-1");return;}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);puts("");
}
int main(){
	freopen("safe.in","r",stdin);freopen("safe.out","w",stdout);
//	freopen("Cola.txt","r",stdin);
	int T;scanf("%d",&T);
	for(int i=1;i<=810000;i++)f[i]=count(i);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&k);
		if(k<=100){work1();continue;}
		if(a==1&&c==0){work2();continue;}
		if(b==1&&c==0){work3();continue;}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
