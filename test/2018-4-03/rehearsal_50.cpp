#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010
using namespace std;
int n;
struct node{
	int s,t,w,id,ans;
}a[maxn];
int qread(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("rehearsal.in","r",stdin);freopen("rehearsal.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++){
		a[i].s=qread();a[i].t=qread();a[i].w=qread();
		a[i].id=i;
	}
	int last;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--)
			if(a[j].s<a[i].s){
				last=j;
				if(a[j].t<a[i].t)a[i].ans+=a[j].w;
				break;
			}
		for(int j=last-1;j>=1;j--){
			if(a[j].s>a[last].s&&a[j].s<a[i].s){
				last=j;
				if(a[j].t<a[i].t)a[i].ans+=a[j].w;
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d\n",a[i].ans);
}
