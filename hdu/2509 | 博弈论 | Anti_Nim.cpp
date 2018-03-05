#include<iostream>
#include<cstdio>
int flag,x,sum,n;
int main(){
	while(scanf("%d",&n)!=EOF){
		flag=sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x!=1)flag=1;
			sum^=x;
		}
		if(((flag==1)&&(sum!=0))||(!flag&&!sum))puts("Yes");
		else puts("No");
	}
	return 0;
}
