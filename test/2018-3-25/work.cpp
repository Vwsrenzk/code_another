#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200010
using namespace std;
int L[maxn],T[maxn];
long long s0[maxn*4],s1[maxn*4],s2[maxn*4];
void update(int k,int l,int r){
	if(l==r){
		s1[k]=s0[k]*l;
		s2[k]=s0[k]*(s0[k]+1)/2*l;
	}
	else{
		int lc=k<<1,rc=k<<1|1;
		s0[k]=s0[lc]+s0[rc];
		s1[k]=s1[lc]+s1[rc];
		s2[k]=s2[lc]+s2[rc]+s0[rc]*s1[lc];
	}
}
void modify(int k,int l,int r,int opx,int opv){
	if(r<opx||l>opx)return;
	if(l==r)s0[k]+=opv;
	else{
		int mid=(l+r)>>1;
		modify(k<<1,l,mid,opx,opv);
		modify(k<<1|1,mid+1,r,opx,opv);
	}
	update(k,l,r);
}
int main(){
	freopen("work.in","r",stdin);freopen("work.out","w",stdout);
//	freopen("Cola.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	long long suml=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&L[i],&T[i]);
		suml+=L[i];
		modify(1,1,100000,T[i],1);
	}
	printf("%I64d\n",suml-s2[1]);
	while(m--){
		int a;scanf("%d",&a);
		modify(1,1,100000,T[a],-1);
		suml-=L[a];
		scanf("%d%d",&L[a],&T[a]);
		suml+=L[a];
		modify(1,1,100000,T[a],1);
		printf("%I64d\n",suml-s2[1]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
