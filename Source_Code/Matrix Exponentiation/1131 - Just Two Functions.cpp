#include<stdio.h>
#include<string.h>

#define maxm 100
#define ii long long int

ii mod;
ii a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,q,n,a3,b3,c3;
ii dp[maxm],dp1[maxm];
ii f(ii n);
ii g(ii n);

ii base[6][6]={{1,1,1,1,0,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
ii unit[6][6]={{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
ii res[6][6];


void cal(ii a[6][6],ii b[6][6]){

	ii ret[6][6]; int i,j,k;
	memset(ret,0,sizeof(ret));

	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			for(k=0;k<6;k++){
				ret[i][j]+=(a[i][k]*b[k][j]);
				if(ret[i][j]<0) ret[i][j]+=mod;
				ret[i][j]%=mod;
			}
		}
	}

	memcpy(a,ret,sizeof(ret));

}


void exp(ii r[6][6],ii n){

	ii b[6][6];
	memcpy(r,unit,sizeof(unit));
	memcpy(b,base,sizeof(base));

	while(n>0){
		if(n%2==1) cal(r,b);
		n/=2;
		cal(b,b);
	}
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%lld %lld %lld",&a1,&b1,&c1);
		scanf("%lld %lld %lld",&a2,&b2,&c2);
		scanf("%lld %lld %lld",&f0,&f1,&f2);
		scanf("%lld %lld %lld",&g0,&g1,&g2);
		scanf("%lld %lld",&mod,&q);

		printf("Case %d:\n",t++);

		memset(dp,-1,sizeof(dp));
		memset(dp1,-1,sizeof(dp1));

		base[0][0]=a1+a2; base[0][1]=b1-(a1*a2)+b2; base[0][2]=(-(b1*a2+a1*b2)); base[0][3]=(-(b1*b2)); base[0][5]=c1*c2;
		base[0][0]%=mod; if(base[0][1]<0) base[0][1]+=mod; base[0][1]%=mod; base[0][2]+=mod;  base[0][3]+=mod;  base[0][5]%=mod;

		ii ans=0;

		for(j=1;j<=q;j++){
			ans=0;
			scanf("%lld",&n);
			if(n<=5) ans=f(n);
			else {
			    exp(res,n-5);
			    for(i=0;i<6;i++){
			        ans+=(res[0][i]*f(5-i));
			        if(ans<0) ans+=mod;
			        ans%=mod;
			    }
			}
			ans%=mod;
			printf("%lld ",ans);
			ans=0;
			if(n<=5) ans=g(n);
			else {
			    for(i=0;i<6;i++){
			        ans+=(res[0][i]*g(5-i));
			        if(ans<0) ans+=mod;
			        ans%=mod;
			    }
			}
			ans%=mod;
			printf("%lld\n",ans);

		}

	}

	return 0;
}

ii f(ii n){

	if(n==0) return f0;
	if(n==1) return f1;
	if(n==2) return f2;

	if(dp[n]!=-1) return dp[n];

	ii ret=0;

	ret=a1*f(n-1);
	ret%=mod;
	ret+=(b1*f(n-2));
	ret%=mod;
	ret+=(c1*g(n-3));
	ret%=mod;
	return dp[n]=ret;

}
ii g(ii n){

	if(n==0) return g0;
	if(n==1) return g1;
	if(n==2) return g2;

	if(dp1[n]!=-1) return dp1[n];

	ii ret=0;

	ret=a2*g(n-1);
	ret%=mod;
	ret+=(b2*g(n-2));
	ret%=mod;
	ret+=(c2*f(n-3));
	ret%=mod;
	return dp1[n]=ret;

}
