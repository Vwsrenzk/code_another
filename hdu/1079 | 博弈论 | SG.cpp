#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int day[110],SG[110][20][40];
int num[13]={0,31,30,31,30,31,30,31,31,30,31,30,31};
int getSG(int y,int m,int d){
	if(SG[y][m][d]!=-1)return SG[y][m][d];
	if((y==101&&m==11&&d==3)||(y==101&&m==10&&d==4))return SG[y][m][d]=1;
	if(y>101)return SG[y][m][d]=0;
	int flag=0;
	if(m==12){
		if(d==31){
			int a=getSG(y+1,1,1),b=getSG(y+1,1,31);
			if(a==0||b==0)return SG[y][m][d]=1;
			else return SG[y][m][d]=0;
		}
		else {
			int a=getSG(y,m,d+1),b=getSG(y+1,1,d);
			if(a==0||b==0)return SG[y][m][d]=1;
			else return SG[y][m][d]=0;
		}
	}
	else if(m==1){
		if(d>day[y]){
			if(d!=num[1]){
				int a=getSG(y,m,d+1);
				if(a==0)return SG[y][m][d]=1;
				else return SG[y][m][d]=0;
			}
			else{
				int a=getSG(y,m+1,1);
				if(a==0)return SG[y][m][d]=1;
				else return SG[y][m][d]=0;
			}
		}
		else{
			int a=getSG(y,m,d+1),b=getSG(y,m+1,d);
			if(a==0||b==0)return SG[y][m][d]=1;
			else return SG[y][m][d]=0;
		}
	}
	else if(d>num[m+1]){//只能走到下一天 
		int a=getSG(y,m+1,1);
		if(a==0)return SG[y][m][d]=1;
		else return SG[y][m][d]=0;
	}
	else{
		int a,b=getSG(y,m+1,d);
		if(d==num[m])a=getSG(y,m+1,1);
		else a=getSG(y,m,d+1);
		if(a==0||b==0)return SG[y][m][d]=1;
		else return SG[y][m][d]=0;
	}
}
int main(){
	int y,m,d;
	memset(SG,-1,sizeof(SG));
	for(int i=1900;i<=2001;i++){
		if((i%4==0&&i%100!=0)||(i%400==0))day[i-1900+1]=29;
		else day[i-1900+1]=28;
	}
	SG[101][11][4]=0;
	for(int i=5;i<=30;i++)SG[101][11][i]=1;
	for(int i=1;i<=31;i++)SG[101][12][i]=1;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&y,&m,&d);
		y-=1900;
		getSG(y,m,d);
		if(SG[y][m][d]==1)puts("YES");
		else puts("NO");
	}
	return 0;
}
