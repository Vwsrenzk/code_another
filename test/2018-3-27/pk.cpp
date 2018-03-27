#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<algorithm>

using namespace std;

const int BUF_SIZE = 30;
char buf[BUF_SIZE], *buf_s = buf, *buf_t = buf + 1;
  
#define PTR_NEXT() \
    { \
        buf_s ++; \
        if (buf_s == buf_t) \
        { \
            buf_s = buf; \
            buf_t = buf + fread(buf, 1, BUF_SIZE, stdin); \
        } \
    }
   
#define readint(_n_) \
    { \
        while (*buf_s != '-' && !isdigit(*buf_s)) \
            PTR_NEXT(); \
        bool register _nega_ = false; \
        if (*buf_s == '-') \
        { \
            _nega_ = true; \
            PTR_NEXT(); \
        } \
        int register _x_ = 0; \
        while (isdigit(*buf_s)) \
        { \
            _x_ = _x_ * 10 + *buf_s - '0'; \
            PTR_NEXT(); \
        } \
        if (_nega_) \
            _x_ = -_x_; \
        (_n_) = (_x_); \
    }

#define wmt 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn=100010;
const int maxm=maxn*70;

int n,m,z[maxn],cnt;

long long sum[maxn<<2|1];

struct rec
{
	int v,p;
	rec(){}
	rec(int a,int b){v=a;p=b;}
	bool operator<(const rec &a)const {
		if (v!=a.v) return v<a.v;
		else return p<a.p;
	}
}y[maxm];

int next[maxm],front[maxm],first[maxn*10],last[maxn*10];

bool del[maxm];

inline void update(int rt) {
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

inline void build(int l,int r,int rt)
{
	if (l==r) {
		sum[rt]=z[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}

inline long long query(int l,int r,int rt,int nowl,int nowr) {
	if (nowl<=l && r<=nowr) return sum[rt];
	int m=(l+r)>>1;
	long long ans=0;
	if (nowl<=m) ans+=query(lson,nowl,nowr);
	if (m<nowr) ans+=query(rson,nowl,nowr);
	return ans;
}

inline void modify(int l,int r,int rt,int p,int v) {
	if (l==r) {
		sum[rt]=v;
		return;
	}
	int m=(l+r)>>1;
	if (p<=m) modify(lson,p,v);
	else modify(rson,p,v);
	update(rt);
}

int main()
{
	freopen("pk.in","r",stdin);
	freopen("pk.out","w",stdout);

	readint(n);
	readint(m);
	for (int a=1;a<=n;a++)
	{
		readint(z[a]);
		for (int b=2;b*b<=z[a];b++)
			if (z[a]%b==0) {
				y[++cnt]=rec(b,a);
				if (b*b!=z[a]) y[++cnt]=rec(z[a]/b,a);
			}
		y[++cnt]=rec(z[a],a);
	}
	sort(y+1,y+cnt+1);
	for (int a=1;a<=cnt;a++)
		last[y[a].v]=a;
	for (int a=cnt;a>=1;a--)
		first[y[a].v]=a;
	for (int a=1;a<=cnt;a++)
	{
		if (y[a].v==y[a-1].v) front[a]=a-1;
		if (y[a].v==y[a+1].v) next[a]=a+1;
	}

	build(wmt);
	int opt,l,r,v;
	for (int a=1;a<=m;a++)
	{
		readint(opt);
		readint(l);
		readint(r);
		if (opt==1) {
			readint(v);
			if (v==1) continue;
			if (!first[v]) continue;
			int left=first[v]-1,right=last[v];
			while (left+1!=right)
			{
				int m=(left+right)>>1;
				if (y[m].p>=l) right=m;
				else left=m;
			}
			int p=right;
			while (y[p].v==v && y[p].p<=r && y[p].p>=l) {
				if (del[p]) 
				{
					p=next[p];
					continue;
				}
				int px=y[p].p;
				if (z[px]%v==0) {
					z[px]/=v;
					modify(wmt,px,z[px]);
				}
				if (z[px]%v!=0) {
					del[p]=true;
					if (!front[p]) {
						if (!next[p]) first[v]=last[v]=0;
						else {
							first[v]=next[p];
							front[next[p]]=0;
						}
					}
					else {
						if (!next[p]) {
							last[v]=front[p];
							next[front[p]]=0;
						}
						else {
							front[next[p]]=front[p];
							next[front[p]]=next[p];
						}
					}
				}
				p=next[p];
			}
		}
		else printf("%I64d\n",query(wmt,l,r));
	}

	return 0;
}

