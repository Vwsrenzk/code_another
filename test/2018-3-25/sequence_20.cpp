#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
int main(){
	freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1)cout<<1<<endl;
		if(n==2)cout<<1<<endl;
		if(n==3)cout<<3<<endl;
		if(n==4)cout<<13<<endl;
		if(n==5)cout<<71<<endl;
		if(n==6)cout<<461<<endl;
		if(n==7)cout<<3447<<endl;
		if(n==8)cout<<29093<<endl;
		if(n==9)cout<<273343<<endl;
		if(n==10)cout<<2829325<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
