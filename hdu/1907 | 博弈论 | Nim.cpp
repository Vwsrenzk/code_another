#include<iostream>
#include<cstdio>
int T,flag,x,sum,n;
int main(){
	scanf("%d",&T);
	while(T--){
		flag=sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x!=1)flag=1;
			sum^=x;
		}
		if(((flag==1)&&(sum!=0))||(!flag&&!sum))puts("John");
		else puts("Brother");
	}
	return 0;
}
