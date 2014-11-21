#include<stdio.h>
#include<string.h>
#include<math.h>

//#define ii __int64
#define ii long long int

ii m,n,dp[15][5][4],dp1[15][5][5];
int a[15];
ii cal(int ind,int fl,int z);
ii cal1(int ind,int fl,int z);

int main(){
	
	int i,j,k,l,test,t=1;
	
	//freopen("in.txt","r",stdin);

//	scanf("%d",&test);

	while(1){

		scanf("%lld %lld",&m,&n);
		if(m<0) break;
		k=0;
		for(i=0;i<=11;i++) a[i]=0;
		while(n){
			a[k++]=n%10; n/=10;
		}
		for(k=11;k>=0;k--){
			if(a[k]!=0) break;
		}
		memset(dp,-1,sizeof(dp));
		memset(dp1,-1,sizeof(dp1));
		ii ans=0;
		ans=cal(k,0,0);
		if(!m){
			printf("%lld\n",ans+1);
			continue;
		}
		m--;
		k=0;
		for(i=0;i<=10;i++) a[i]=0;
		while(m){
			a[k++]=m%10; m/=10;
		}
		for(k=10;k>=0;k--){
			if(a[k]!=0) break;
		}
		memset(dp,-1,sizeof(dp));
		memset(dp1,-1,sizeof(dp1));
		ii ans2=0;
		ans2=cal(k,0,0);

		printf("%lld\n",ans-ans2);


	}

	return 0;
}

ii cal(int ind,int fl,int z){
	
	if(ind<0) return 0;

	if(dp[ind][fl][z]!=-1) return dp[ind][fl][z];

	int i,j,k,l;
	ii ret=0;

	if(!fl){	
		
		for(i=0;i<a[ind];i++){
			if(i==0){
				ret+=cal(ind-1,1,z);
				if(z) ret+=cal1(ind-1,1,z);
				continue;
			}
			ret+=cal(ind-1,1,1);
		}
		if(a[ind]==0){
			ret+=cal(ind-1,0,z);
			ret+=cal1(ind-1,0,z);
		}
		else{
			ret+=cal(ind-1,0,1);
		}		
	}
	else{
		ret=cal(ind-1,1,z);
		if(z) ret+=cal1(ind-1,1,z);
		for(i=1;i<=9;i++){
			ret+=cal(ind-1,1,1);
		}		
	}
	
	return dp[ind][fl][z]=ret;
	
}
ii cal1(int ind,int fl,int z){
	
	if(ind<0&&z) return 1;
	if(ind<0) return 0;

	if(dp1[ind][fl][z]!=-1) return dp1[ind][fl][z];

	int i,j,k,l;
	ii ret=0;

	if(!fl){
		
		for(i=0;i<a[ind];i++){
			if(i==0) ret+=cal1(ind-1,1,z);
			else ret+=cal1(ind-1,1,1);
		}
		if(a[ind]!=0) z=1;
		ret+=cal1(ind-1,0,z);
		
	}
	else{
		ret+=cal1(ind-1,1,z);
		for(i=1;i<=9;i++){
			ret+=cal1(ind-1,1,1);
		}
	}
	
	return dp1[ind][fl][z]=ret;
	
}

