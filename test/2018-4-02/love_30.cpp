#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
int n,cnt,len[101],tot[101][101],nxt[101],l;
char s[101][101];
bool a[101][101][101];
void work(int pos){
	len[pos]=strlen(s[pos]);
	for(int i=0;i<len[pos];i++){
		a[pos][i][i]=1;
		for(int j=i+1;j<len[pos];j++){
			int l=i,r=j,flag=0;
			while(l<r){
				if(s[pos][l]!=s[pos][r]){flag=1;break;}
				l++;r--;
			}
			if(!flag)a[pos][i][j]=1;
		}
	}
}
char c[101];
void getnxt(){
    int i=0,j=-1;l=strlen(c);
    nxt[0]=-1;
    while(i!=l){
        if(c[i]==c[j]||j==-1)nxt[++i]=++j;
        else j=nxt[j];
    }
}
void solve(){
	int ans=0;
	for(int pos=1;pos<=n;pos++){
		int i=0,j=0;
		while(i!=len[pos]&&j!=l){
			if(c[j]==s[pos][i]||j==-1)i++,j++;
			else j=nxt[j];
			if(j==l){
				for(int st=1;st+l-1<=i;st++)
					if(a[pos][st-1][i-1])ans++;
				ans--;
				j=nxt[j];
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("love.in","r",stdin);freopen("love.out","w",stdout);
	scanf("%d",&n);
	int op;
	for(int i=1;i<=n;i++){
		scanf("%d",&op);
		if(op==1){
			cnt++;
			scanf("%s",s[cnt]);
			work(cnt);
		}
		else {
			scanf("%s",c);
			memset(nxt,0,sizeof(nxt));
			getnxt();
			solve();
		}
	}
}
