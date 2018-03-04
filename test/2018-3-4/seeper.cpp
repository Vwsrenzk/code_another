#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50010
using namespace std;
int a[maxn],b[maxn],c[maxn];
char s[maxn];
struct node{
	int zu[maxn],len;
	node(){memset(zu,0,sizeof(zu));len=0;}
	node operator * (const node &x)const{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int len1=len,len2=x.len;
		for(int i=1,j=len1;i<=len1;i++,j--)a[i]=zu[j];
		for(int i=1,j=len2;i<=len2;i++,j--)b[i]=x.zu[j];
		int cnt=0;
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				c[j+cnt]+=a[i]*b[j];
				if(c[j+cnt]>=10){
					c[j+cnt+1]+=c[j+cnt]/10;
					c[j+cnt]%=10;
				}
			}
			cnt++;
		}
		int l=len1+len2;
		while(c[l]>=10){
			l++;
			c[l]+=c[l-1]/10;
			c[l-1]%=10;
		}
		node res;res.len=l;
		for(int i=1,j=l;i<=l;i++,j--)res.zu[i]=c[j];
		return res;
	}
	node operator / (const int &x)const{
		memset(a,0,sizeof(a));
		int tmp=0;
		for(int i=1;i<=len;i++){
			tmp=tmp*10+zu[i];
			a[i]=tmp/x;
			tmp%=x;
		}
		int t=len;
		int h=1;
		while((h<t)&&(a[h]==0))h++;
		node res;res.len=t-h+1;
		for(int i=h,j=1;i<=t;i++,j++)res.zu[j]=a[i];
		return res;
	}
	node operator - (const int &x)const{
		memset(a,0,sizeof(a));
		for(int i=1,j=len;i<=len;i++,j--)a[i]=zu[j];
		a[1]-=x;
		for(int i=1;i<=len;i++){
			if(a[i]<0){
				a[i]+=10;
				a[i+1]--;
			}
			else break;
		}
		int l=len;
		while((l>1)&&(a[l]==0))l--;
		node res;res.len=l;
		for(int i=1,j=l;i<=l;i++,j--)res.zu[i]=a[j];
		return res;
	}
};
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("seeper.in","r",stdin);freopen("seeper.out","w",stdout);
	scanf("%s",s+1);
	node n;
	n.len=strlen(s+1);
	for(int i=1;i<=n.len;i++){n.zu[i]=s[i]-'0';}
	
	if(((n.len==1)&&(n.zu[1]<=3))||(n.zu[n.len]&1)){
		puts("0");
		fclose(stdin);fclose(stdout);
		return 0;
	}
	
	node m=n/2;
	node ans=m*m*(m*m-1)/12;
	for(int i=1;i<=ans.len;i++)printf("%d",ans.zu[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
