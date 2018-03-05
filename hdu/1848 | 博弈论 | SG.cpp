#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[30],SG[1010],a[5];
int getSG(int x){
	bool flag[1010]={0};
	for(int i=1;i<=20;i++){
		if(f[i]>x)break;
		int tmp=x-f[i];
		if(SG[tmp]==-1)SG[tmp]=getSG(tmp);
		flag[SG[tmp]]=1;
	}
	for(int i=0;;i++)if(!flag[i])return i;
}
void prepare(){
	f[1]=1;f[2]=2;
	for(int i=3;i<=20;i++)
		f[i]=f[i-1]+f[i-2];
}
int main(){
	memset(SG,-1,sizeof(SG));
	prepare();
	while(1){
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		if(a[1]==0&&a[2]==0&&a[3]==0)return 0;
		int sum=0;
		for(int i=1;i<=3;i++){
			if(SG[a[i]]==-1)SG[a[i]]=getSG(a[i]);
			sum^=SG[a[i]];
		}
		if(sum==0)puts("Nacci");
		else puts("Fibo");
	}
	return 0;
}
