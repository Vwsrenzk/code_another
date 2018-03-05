#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int SG[1000010];
char s[10];
int count(){
	int res=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
		res=res*10+s[i]-'0';
	return res;
}
int getlen(int x){
	int res=0;
	while(x){res++;x/=10;}
	return res;
}
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
void getSG(int x){
	int len=getlen(x);
	for(int i=1;i<=len;i++){
		int k=Pow(10,i-1);
		int p=x/k%10,y=x;
		for(int j=p;j<9;j++){
			y+=k;
			SG[y]=1;
		}
	}
	int y=x,k=1;
	while(len<6){
		y=y*10;
		for(int i=0;i<k;i++)SG[y+i]=1;
		k*=10;
		len++;
	}
}
int main(){
	for(int i=1;i<1000000;i++)
		if(!SG[i])getSG(i);
	while(gets(s)){
		if(s[0]=='0')puts("Yes");
		else{
			int k=count();
			if(SG[k])puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
