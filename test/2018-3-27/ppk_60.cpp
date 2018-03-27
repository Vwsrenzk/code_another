#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;
int n,m,cnt,q[maxn];
struct node{
	long long x,y;
	node operator - (const node b)const{
		node res;res.x=x-b.x;res.y=y-b.y;
		return res;
	}
	long long operator * (const node b)const{
		return x*b.y-y*b.x;
	}
	bool operator < (const node b)const{
		if(x!=b.x)return x<b.x;
		return y<b.y;
	}
	bool operator == (const node b)const{
		return x==b.x&&y==b.y;
	}
}p1[maxn],p2[maxn],p[maxn];
long long Cross(int a,int b,int c){
	return (p[a]-p[b])*(p[c]-p[b]);
}
int r;
void get(){
	r=0;
	for(int i=1;i<=cnt;i++){
		while(r>1&&Cross(q[r],q[r-1],i)>=0)r--;
		q[++r]=i;
	}
	int rr=r;
	for(int i=cnt-1;i>=1;i--){
		while(r>rr&&Cross(q[r],q[r-1],i)>=0)r--;
		q[++r]=i;
	}
}
long long qread(){
	long long i=00,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("ppk.in","r",stdin);freopen("ppk.out","w",stdout);
	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++)scanf("%lf%lf",&p1[i].x,&p1[i].y);
//	for(int i=1;i<=m;i++)scanf("%lf%lf",&p2[i].x,&p2[i].y);
	for(int i=1;i<=n;i++)p1[i].x=qread(),p1[i].y=qread();
	for(int i=1;i<=m;i++)p2[i].x=qread(),p2[i].y=qread();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			p[++cnt].x=p1[i].x+p2[j].x;
			p[cnt].y=p1[i].y+p2[j].y;
		}
	sort(p+1,p+cnt+1);
	cnt=unique(p+1,p+cnt+1)-p-1;
	get();
	long long ans=0;
	q[0]=q[r-1];
	for(int i=2;i<r-1;i++){
		node a=p[q[i]]-p[q[1]];
		node b=p[q[i+1]]-p[q[1]];
//		cout<<a.x<<' '<<a.y<<' '<<b.x<<' '<<b.y<<endl;
		ans+=a*b;
	}
	if(ans<0)ans=-ans;
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
