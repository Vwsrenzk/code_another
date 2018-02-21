#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll p=1e8;
const ll f[]={1,1,1e1,1e2,1e3,1e4,1e5,1e6,1e7};
char s[10005];

struct bigint
{
	ll a[10005],len;
	
	bigint (){
		memset(a,0,sizeof(a));
		len=1;
	}
	
	void read(){
		scanf("%s",s+1);
		int l=strlen(s+1),k=0;ll h=0;
		len=0;
		for (int i=l;i>=1;i--) {
			k++;
			h=h+(s[i]-'0')*f[k];
			if (k==8){
				k=0;a[++len]=h;h=0;
			}
		}
		if (h>0) a[++len]=h;
	}
	void write(){
		if (len==0) len++;
		for (int i=len;i>=1;i--){
			if (i==len) printf("%I64d",a[i]);
			else printf("%08I64d",a[i]);
		}
	}
	
	bigint operator /(int b){
		bigint c;c.len=len;
		ll tmp=0;
		for (int i=len;i>=1;i--){
			tmp=tmp*p+a[i];
			c.a[i]=tmp/b,tmp=tmp%b;
		}
		while (c.len>1&&c.a[c.len]==0) c.len--;
		return c;
	} 
	
	bigint operator *(const bigint &b){
		bigint c;
		c.len=len+b.len;
		for (int i=1;i<=len;i++)
			for (int j=1;j<=b.len;j++) 
				c.a[i+j-1]+=a[i]*b.a[j];
		for (int i=1;i<=c.len;i++) c.a[i+1]+=c.a[i]/p,c.a[i]%=p;
		while (c.len>1&&c.a[c.len]==0) c.len--;
		return c;
	}
	bigint operator -(int b){
		bigint c=*this;
		c.a[1]-=b;
		for (int i=1;i<=c.len;i++) 
			if (c.a[i]<0) c.a[i+1]--,c.a[i]+=p;
		while (c.len>1&&c.a[c.len]==0) c.len--;
		return c;
	}
}tmp,t,n,t1,t2;


int main(){
	freopen("seeper.in","r",stdin);
	freopen("seeper.out","w",stdout);
	n.read();
	if(n.a[1]&1){
		printf("0");
		return 0;
	}
	t=n/2;
	tmp=t*t*(t*t-1)/12;
	tmp.write();
	return 0;
}
