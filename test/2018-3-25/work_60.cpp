#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200010
using namespace std;
int n,m,be[maxn];
int qread(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
struct node{
	int l,t,id;
	bool operator < (const node x)const{
		if(t!=x.t)return t<x.t;
		return l>x.l;
	}
}a[maxn];
void work(){
	long long tim=0,ans=0;
	for(int i=1;i<=n;i++){
		tim+=a[i].t;
		ans+=a[i].l-tim;
	}
	printf("%I64d\n",ans);
}
bool cmp(node x,node y){return x.id<y.id;}
int main(){
//	freopen("Cola.txt","r",stdin);freopen("1.out","w",stdout);
	freopen("work.in","r",stdin);freopen("work.out","w",stdout);
	n=qread();m=qread();
	for(int i=1;i<=n;i++){
		a[i].l=qread();
		a[i].t=qread();
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)be[a[i].id]=i;
	work();
	int x,y,z;
	while(m--){
		scanf("%d%d%d",&x,&y,&z);
		a[be[x]].l=y;a[be[x]].t=z;
		int pos=be[x];
		if(pos==1){
			if(a[pos+1]<a[pos]){
				node tmp=a[pos];
				int to=lower_bound(a+pos+2,a+n+1,a[pos])-a-1;
				for(int i=pos;i<to;i++)a[i]=a[i+1];
				a[to]=tmp;
			}
		}
		else if(a[pos-1]<a[pos]&&a[pos]<a[pos+1]);
		else if(a[pos]<a[pos-1]){//插到前半部分 
			int to=lower_bound(a+1,a+pos+1,a[pos])-a-1;
			node tmp=a[pos];
			for(int i=pos;i>to+1;i--)a[i]=a[i-1];
			if(to==n)to=n-1;
			a[to+1]=tmp;
		}
		else {//插到后半部分 
			node tmp=a[pos];
			int to=lower_bound(a+pos+1,a+n+1,a[pos])-a-1;
			for(int i=pos;i<to;i++)a[i]=a[i+1];
			a[to]=tmp;
		}
		for(int i=1;i<=n;i++)be[a[i].id]=i;
		work();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
