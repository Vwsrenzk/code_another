/*source bzoj3755*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010
using namespace std;
int n,x[maxn],y[maxn],maxid;
double k[1010][1010];
bool look[1010][1010];
int qread(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
	return i*j;
}
struct node{
	int x,y,to;
	bool operator < (const node &b)const{
		if(y!=b.y)return y<b.y;
		return x<b.x;
	}
}p[maxn];
double count(int i,int j){
	double ans=(double)(p[i].y-p[j].y)/(double)(p[i].x-p[j].x);
	return ans;
}
void find(int id){
	int step=0,now_max_to=p[id].to;
	while(id!=maxid){
		int to=p[id].to;
		if(p[now_max_to]<p[to])now_max_to=to;
		if(p[now_max_to].x<p[id].x){id--;}
		else id++;
		step++;
	}
	printf("%d\n",step);
}
int main(){
//	freopen("Cola.txt","r",stdin);
	freopen("mountain.in","r",stdin);freopen("mountain.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++)p[i].x=qread(),p[i].y=qread();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			k[i][j]=k[j][i]=count(i,j);
	for(int i=1;i<=n;i++){
		double mn=1000000000;
		for(int j=i-1;j>=1;j--){
			if(k[i][j]>mn)continue;
			mn=min(mn,k[i][j]);
			if(p[p[i].to]<p[j])p[i].to=j;
		}
		double mx=-1000000000;
		for(int j=i+1;j<=n;j++){
			if(k[i][j]<mx)continue;
			mx=max(mx,k[i][j]);
			if(p[p[i].to]<p[j])p[i].to=j;
		}
	}
	p[0].x=-1,p[0].y=-1;
	for(int i=1;i<=n;i++)
		if(p[maxid]<p[i])maxid=i;
	for(int i=1;i<=n;i++){
		find(i);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
