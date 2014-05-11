#include<stdio.h>
#include<string.h>

#define ii long long int
#define maxm 1000100
#define mod 1000003

struct node{
	ii x,y,g;
	node(){};
	node(ii xx,ii yy,ii gg){ x=xx; y=yy; g=gg;};
};

ii norm[maxm],inv[maxm],invr[maxm];
bool flag[maxm];

void gen(int n);
ii mod_inv(ii a,ii n);
node euclid(ii a,ii b);

int main(){

	int i,j,k,l,test,t=1,n;
	
//	freopen("in.txt","r",stdin);
	gen(maxm-90);
	scanf("%d",&test);
	
	while(test--){

		scanf("%d %d",&n,&k);
		ii ans=(norm[n]*inv[k])%mod;
		ans=(ans*inv[n-k])%mod;
		printf("Case %d: %lld\n",t++,ans);
		
	}

	return 0;
}

node euclid(ii a,ii b){

	if(!b) return node(1,0,a);
	node r=euclid(b,a%b);
	return node(r.y,r.x-(a/b)*r.y,r.g);
}

ii mod_inv(ii a,ii n){
	
	if(flag[a]) return invr[a];
	node t=euclid(a,n);
	if(t.g>1) return 0;
	ii ret=t.x%n;
	ret= ret<0 ? ret+n:ret;
	flag[a]=1;
	flag[ret]=1;
	invr[ret]=a;
	return ret;

}

void gen(int n){

	int i,j,k,l;

	
	norm[0]=1;
	inv[0]=1;

	for(i=1;i<=n;i++){
		norm[i]=(i*norm[i-1])%mod;
		inv[i]=mod_inv(norm[i],mod);
	}

}