void prepare(){
	phi[1]=1;
	for(int i=2;i<=40000;i++){
		if(!vis[i])p[++cnt]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&i*p[j]<=40000;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}
