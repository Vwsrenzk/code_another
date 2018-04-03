#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1100010
using namespace std;
unsigned long long has[maxn];
char s[2010];
int len,cnt;
void check(int sta){
	string ss="";int l1=0;
	unsigned long long h=0;
	for(int i=0;i<len;i++)
		if((1<<i)&sta){
			ss+=s[i];
			h=h*26+s[i]-'a'+1;
			l1++;
		}
	int l=0,r=l1-1,flag=0;
	while(l<r){
		if(ss[l]!=ss[r]){flag=1;break;}
		else l++,r--;
	}
	if(flag)return;
	else {
		has[++cnt]=h;
	}
}
int main(){
	freopen("library.in","r",stdin);freopen("library.out","w",stdout);
//	freopen("Cola.txt","r",stdin);freopen("qwq.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	for(int i=1;i<(1<<len);i++){
		check(i);
	}
	sort(has+1,has+cnt+1);
	int cnt2=unique(has+1,has+cnt+1)-has-1;
	printf("%d",cnt-cnt2);
	fclose(stdin);fclose(stdout);
	return 0;
}
