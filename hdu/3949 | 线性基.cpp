#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10010
using namespace std;
int n,q,cnt;
long long a[maxn],b[70],c[70],rk;
long long qread(){
	long long i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
long long query(long long k){
	if(k>=(1LL<<cnt))return -1;
	long long res=0;
	for(int i=0;i<cnt;i++)if((k>>i)&1)res^=c[i];
	return res;
}
int main(){
	int T;scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		printf("Case #%d:\n",cas);
		scanf("%d",&n);cnt=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)a[i]=qread();
		for(int i=1;i<=n;i++)
			for(int j=63;j>=0;j--)
				if((a[i]>>j)&1){
					if(b[j])a[i]^=b[j];
					else{
						b[j]=a[i];
						for(int k=j-1;k>=0;k--)
							if(((b[j]>>k)&1)&&b[k])b[j]^=b[k];
						for(int k=j+1;k<=63;k++){
							if((b[k]>>j)&1)b[k]^=b[j];
						}
						break;
					}
				}
		for(int i=0;i<=63;i++)if(b[i])c[cnt++]=b[i];
		scanf("%d",&q);
		while(q--){
			rk=qread();
			if(cnt!=n)rk--;
			cout<<query(rk)<<endl;
		}
	}
	return 0;
}
