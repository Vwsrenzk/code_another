#include<iostream>  
#include<cstdio> 
using namespace std;  
int main(){  
    int a,b;  
    while(scanf("%d%d",&a,&b)!=EOF&&a+b){  
        if(a<b)swap(a,b);  
        bool stan=true;  
        while(1){             
            if(b==0||a%b==0||a/b>=2) break;  
            int t=a;  
            a=b;  
            b=t-a;  
            stan=!stan;  
        }  
        if(stan)puts("Stan wins");  
        else puts("Ollie wins");  
    }  
    return 0;  
}  
