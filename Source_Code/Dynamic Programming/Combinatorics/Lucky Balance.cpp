#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 5020
#define mod 1000000007
#define ii long long int

struct node{
	ii x,y,g;
	node(){};
	node(ii xx,ii yy,ii gg){ x=xx; y=yy; g=gg;};
};

ii norm[maxm],inv[maxm];

void gen(int n);
ii mod_inv(ii a,ii n);
node euclid(ii a,ii b);

char s[maxm];
int dp[maxm][maxm/2];
bool v[maxm][maxm/2];
int count4,count7,n;
ii npr(int n1,int n2);
ii cal(int ind,int last,int rem);
ii cal1();
int mini(int a,int b){
    if(a<b) return a; return b;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    gen(maxm-5);

    scanf("%d",&test);
    gets(s);

    while(test--){

        count4=0; count7=0;
        gets(s);
        for(i=0;s[i];i++){
            if(s[i]=='4') count4++;
            else count7++;
        }
        n=count4+count7;
        //printf("n is %d\n",n);
        memset(dp,0,sizeof(dp));
        printf("%lld\n",cal1());

        //memset(v,0,sizeof(v));
        //printf("%lld\n",cal(1,0,count7));

    }

    return 0;
}

ii cal1(){

    int i,j,k,l,rem;
    ii ret;

    //dp[n+1][0]=1;

    for(i=n;i>=1;i--){
        for(j=mini(count4,i);j>=0;j--){
            rem=(count7-(i-1-j));
            if(j>(n/2)||rem>count7||rem<0){
                dp[i][j]=0; continue;
            }
            ret=0;
            if(j==rem){
                if(j<count4){
                    ret+=npr(rem,count4-j-1);
                }
                ret+=dp[i+1][j];
                ret%=mod;
                dp[i][j]=ret; continue;
            }
            if(j==rem-1){
                if(rem>0){
                    ret+=npr(rem-1,count4-j);
                }
                ret+=dp[i+1][j+1]; ret%=mod;
                dp[i][j]=ret; continue;
            }
            ret=dp[i+1][j+1]+dp[i+1][j]; ret%=mod;
            dp[i][j]=ret;
        }
    }

    return dp[1][0];
}
ii cal(int ind,int last,int rem){

    if(last>count4||rem<0) return 0;
    if(ind>n){
        if(last==0) return 1;
        else return 0;
    }
    if(last>rem||last>(n/2)) return 0;


    if(v[ind][last]) return dp[ind][last];
    v[ind][last]=1;

    ii ret=0;
    int len=n-ind+1;

    if(last==rem){
        if(last<count4){
            ret+=npr(rem,count4-last-1);
        }
        ret+=cal(ind+1,last,rem-1);
        ret%=mod;
        return dp[ind][last]=ret;
    }
    if(last==rem-1){
        if(rem>0){
            ret+=npr(rem-1,count4-last);
        }
        ret+=cal(ind+1,last+1,rem);
        ret%=mod;
        return  dp[ind][last]=ret;
    }

    ret=cal(ind+1,last+1,rem)+cal(ind+1,last,rem-1);
    ret%=mod;

    return dp[ind][last]=ret;
}

ii npr(int n1,int n2){

    ii ret=norm[n1+n2];
    ret*=inv[n1]; ret%=mod;
    ret*=inv[n2]; ret%=mod;
    return ret;
}

node euclid(ii a,ii b){

	if(!b) return node(1,0,a);
	node r=euclid(b,a%b);
	return node(r.y,r.x-(a/b)*r.y,r.g);
}

ii mod_inv(ii a,ii n){

	node t=euclid(a,n);
	if(t.g>1) return 0;
	ii ret=t.x%n;
	ret= ret<0 ? ret+n:ret;
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
