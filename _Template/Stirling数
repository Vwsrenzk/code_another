/*第一类Stirling*/
void prepare(){
	for(int i=1;i<=20;i++){
		str[i][0]=0;str[i][i]=1;
		for(int j=1;j<i;j++)
			str[i][j]=(i-1)*str[i-1][j]+str[i-1][j-1];
	}
}


/*第二类Stirling*/
void prepare(){
	str[1][1]=1;
	for(int i=2;i<=2000;i++){
		for(int j=1;j<=i;j++)
			str[i][j]=(j*str[i-1][j]%mod+str[i-1][j-1])%mod;
	}
}
