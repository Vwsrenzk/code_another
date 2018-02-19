#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10000010
using namespace std;
int n,m,head[maxn],num;
long long ans1,ans2,a[maxn],sum;
struct node{
	long long s,v;
	int id,pre;
}e[maxn];
long long qread(){
	long long i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
void Insert(int id,int s,int v){
	e[++num].s=s;
	e[num].v=v;
	e[num].pre=head[id];
	head[id]=num;
}
int main(){
	scanf("%d%d",&n,&m);
	int l,r;long long S,E;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		S=qread();E=qread();
		long long d=(E-S)/(r-l);
		Insert(l,S,d);
		Insert(r+1,-E-d,-d);
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+sum;
		for(int j=head[i];j;j=e[j].pre){
			a[i]+=e[j].s;
			sum+=e[j].v;
		}
		ans1^=a[i];
		ans2=max(ans2,a[i]);
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
