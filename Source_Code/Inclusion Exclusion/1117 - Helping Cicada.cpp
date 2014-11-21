#include<stdio.h>
#include<string.h>

#define maxm 20
#define ii long long int

ii gcd(ii a,ii b){
    if(!a) return b; if(!b) return a;
    return gcd(b,a%b);
}
ii lcm(ii a,ii b){
    ii gc=gcd(a,b);
    a/=gc;
    return a*b;
}

int a[maxm],n,m;
ii ans;
void cal(int now,ii lc,int ind);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);

        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        ans=0;

        cal(0,0,0);

        printf("Case %d: %d\n",t++,n-ans);
    }

    return 0;
}

void cal(int now,ii lc,int ind){

    if(ind>=m){
        if(!lc) return ;
        //printf("lc : %lld\n",lc);
		if(now%2) ans+=(n/lc);
		else ans-=(n/lc);

		return ;
	}
    if(lc>(ii)n) return ;

    ii lc1;

    cal(now,lc,ind+1);

    if(now==0) lc1=a[ind];
    else lc1=lcm(lc,a[ind]);

    cal(now+1,lc1,ind+1);

}
