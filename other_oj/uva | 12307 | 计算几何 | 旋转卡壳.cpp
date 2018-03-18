#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010
#define eps 1e-9
using namespace std;
int n,m;
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	return x<0?-1:1;
}
struct node{
	double x,y;
	node(double x=0,double y=0):x(x),y(y){}
	bool operator < (const node a)const{
		if(!dcmp(x-a.x))return y<a.y;
		return x<a.x;
	}
	node operator - (const node a)const{
		return node(x-a.x,y-a.y);
	}
	bool operator == (const node a)const{
		return !dcmp(x-a.x)&&!dcmp(y-a.y);
	}
}P[maxn],C[maxn];
double Dot(node a,node b){
	return a.x*b.x+a.y*b.y;
}
double Cross(node a,node b){
	return a.x*b.y-a.y*b.x;
}
double dis(node a){
	return sqrt(a.x*a.x+a.y*a.y);
}
int gettubao(node *p,int n,node *c){
	sort(p,p+n);
	n=unique(p,p+n)-p;
	int m=0;
	for(int i=0;i<n;i++){
		while(m>1&&Cross(c[m-1]-c[m-2],p[i]-c[m-2])<=0)m--;
		c[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){
		while(m>k&&Cross(c[m-1]-c[m-2],p[i]-c[m-2])<=0)m--;
		c[m++]=p[i];
	}
	m--;
	return m;
}
void rotatekk(node *c,int m){
	double ans1=1e20,ans2=1e20;
	int q=1,l=0,r=0;
	double d,h,w;
	for(int p=0;p<m;p++){
		while(fabs(Cross(c[p]-c[p+1],c[q+1]-c[p+1]))>fabs(Cross(c[p]-c[p+1],c[q]-c[p+1])))q=(q+1)%m;
		while(dcmp(Dot(c[p+1]-c[p],c[r+1]-c[r]))>0)r=(r+1)%m;
		if(!l)l=q;
		while(dcmp(Dot(c[p+1]-c[p],c[l+1]-c[l]))<0)l=(l+1)%m;
		d=dis(c[p+1]-c[p]);
		h=fabs(Cross(c[p+1]-c[p],c[q]-c[p]))/d;
		w=Dot(c[p+1]-c[p],c[r]-c[l])/d;
		ans1=min(ans1,w*h);
		ans2=min(ans2,(w+h)*2);
	}
	printf("%.2lf %.2lf\n",ans1,ans2);
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)return 0;
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&P[i].x,&P[i].y);
		m=gettubao(P,n,C);
		rotatekk(C,m);
	}
	return 0;
}
