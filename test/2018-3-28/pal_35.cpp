/*source luogu3900*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000010
using namespace std;
char s[maxn],c[maxn];
int n,ans,red[maxn];
int Manacher(int len){
	int k=0,maxlen=0;
	for(int i=len;i>=0;--i){ //插入'#'
		s[i+i+2]=s[i];
		s[i+i+1]='#';
	}
	s[0]='*';
	for(int i=2;i<2*len+1;++i){
		if(red[k]+k>i)red[i]=min(red[2*k-i],red[k]+k-i);
		else red[i]=1;
		while(s[i-red[i]] == s[i+red[i]])++red[i];
		if(k+red[k]<i+red[i])k=i;
		if(maxlen<red[i])maxlen=red[i];
	}
	return maxlen-1;
}
int main(){
	freopen("pal.in","r",stdin);freopen("pal.out","w",stdout);
//	freopen("Cola.txt","r",stdin);
	scanf("%d",&n);
	if(n==1){
		scanf("%s",c);
		int len=strlen(c);
		memset(s,0,sizeof(s));
		for(int i=0;i<len;i++)s[i]=c[i];
		int huiwen1=Manacher(len);
		//-----------------------------------
		for(int i=0;i<len;i++)c[i+len]=c[i];
		len=len+len;
		memset(s,0,sizeof(s));
		for(int i=1;i<=len;i++)s[i]=c[i];
		int huiwen2=Manacher(len);
		//-----------------------------------
		for(int i=0;i<len/2;i++)c[i+len]=c[i];
		len=len+len/2;
		memset(s,0,sizeof(s));
		for(int i=1;i<=len;i++)s[i]=c[i];
		int huiwen3=Manacher(len);
		//-----------------------------------
//		cout<<huiwen1<<' '<<huiwen2<<' '<<huiwen3<<endl;
		if(huiwen3>huiwen2&&huiwen2>huiwen1){puts("Infinity");return 0;}
		else {printf("%d",huiwen3);return 0;}
	}
	else {
		puts("Infinity");
		return 0;
	}
}
