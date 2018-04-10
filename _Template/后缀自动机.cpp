#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 250002
using namespace std;
char s1[maxn],s2[maxn];
int ch[maxn<<1][26],fa[maxn<<1],len[maxn<<1],np,nq,p,q,sz=1,last=1;
void Insert(int c){
	np=++sz;
	len[np]=len[last]+1;
	p=last;
	while(!ch[p][c]&&p)ch[p][c]=np,p=fa[p];
	if(!p)fa[np]=1;
	else {
		q=ch[p][c];
		if(len[q]==len[p]+1)fa[np]=q;
		else {
			nq=++sz;
			memcpy(ch[nq],ch[q],sizeof(ch[nq]));
			fa[nq]=fa[q];
			fa[q]=fa[np]=nq;
			len[nq]=len[p]+1;
			while(ch[p][c]==q)ch[p][c]=nq,p=fa[p];
		}
	}
	last=np;
}
void solve(){
	int l=strlen(s2+1),ans=0,nowlen=0,now=1,c;
	for(int i=1;i<=l;i++){
		c=s2[i]-'a';
		while(now&&!ch[now][c]){
			now=fa[now];
			nowlen=len[now];
		}
		if(!now){
			nowlen=0;
			now=1;
		}
		else {
			nowlen++;
			ans=max(ans,nowlen);
			now=ch[now][c];
		}
	}
	printf("%d",ans);
}
int main(){
	scanf("%s%s",s1+1,s2+1);
	int l=strlen(s1+1);
	for(int i=1;i<=l;i++)Insert(s1[i]-'a');
	solve();
	return 0;
}
