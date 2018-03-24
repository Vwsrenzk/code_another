#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;
double s[maxn];
int n,cnt;
struct node{
	int h,t,id;
	double f;
	bool operator < (const node x)const{
		if(h!=x.h)return h<x.h;
		return t>x.t;
	}
}q[maxn],tmp;
double calc(int x){
	double res=0;
	while(x){
		res+=s[x];
		x-=x&(-x);
	}
	return res;
}
void modify(int x,double v){
	while(x<=n){
		s[x]+=v;
		x+=x&(-x);
	}
}
bool cmp(node x,node y){
	return x.id<y.id;
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("jumping.in","r",stdin);freopen("jumping.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&q[i].h),q[i].id=i;
	for(int i=1;i<=n;i++)scanf("%d",&q[i].t);
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++){
		tmp.h=q[i].h-q[i].t;
		if(q[i].t){
			int j=upper_bound(q+1,q+n+1,tmp)-q-1;
			if(j)q[i].f=1+calc(j)/j;
			else q[i].f=1;
		}
		else {
			int j=lower_bound(q+1,q+n+1,tmp)-q-1;
			int k=upper_bound(q+1,q+n+1,tmp)-q-1;
			cnt=k-j;
			q[i].f=1+calc(j)/k;
			q[i].f=q[i].f*k/(k-cnt);
		}
		modify(i,q[i].f);
	}
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(q[i].f<=1e11&&q[i].f>=-1e11)printf("%.4lf ",(double)q[i].f);
		else printf("0.0000 ");
	return 0;
}
