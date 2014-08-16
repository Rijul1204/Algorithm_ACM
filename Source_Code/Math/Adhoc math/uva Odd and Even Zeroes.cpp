#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;

#define maxm 1100
#define ii long long int
#define MP make_pair

//map<pair<int,int> > mp1;
ii dp[10000];
int val[30][5][5],tot=1;
ii mem[10][50];

ii find(ii n){

    if(n<5) return 0;
    ii val=1;
    for(int i=1;;i++){
        val*=(ii)5;
        if(val>n) return i-1;
        if(val==n) return i;
    }

}
ii poww(ii b,ii p){
    if(!p) return 1;
    if(mem[b][p]) return mem[b][p];
    return mem[b][p]=b*poww(b,p-1);
}

ii cal(ii n,int p,int par,int fl){

    if(p==0){
        if(!par) return (n+1);
		return 0;
    }

    ii piv=poww(5,p);

    if(piv*(ii)5==(n+1)){
        if(val[p][par][fl]) return dp[val[p][par][fl]];
        val[p][par][fl]=tot++;
    }

    ii v=(n+1)/piv;

    ii p0=v/2 + v%2;
    ii p1=v/2;

    ii ret=0;

    if(!fl){
        ret+=(p0*(cal(piv-1,p-1,par,0)));
        ret+=(p1*(cal(piv-1,p-1,!par,1)));
    }
    else{
        ret+=(p1*cal(piv-1,p-1,par,0));
        ret+=(p0*cal(piv-1,p-1,!par,1));
    }

    if((n+1)%piv==0){
        if(piv*(ii)5==(n+1)){
            return dp[val[p][par][fl]]=ret;
        }
        return ret;
    }

    ii val=((n+1)/piv)%2;

    if(val && fl){
        ret+=cal(n%piv,p-1,par,0);
    }
    else if(!val && fl){
        ret+=cal(n%piv,p-1,!par,1);
    }

    else if(val && !fl){
        ret+=cal(n%piv,p-1,!par,1);
    }
    else if(!val && !fl){
        ret+=cal(n%piv,p-1,par,0);
    }

    return ret;
}

ii n;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    while(scanf("%lld",&n)==1){

        if(n==-1) break;

        if(n<5){
            printf("%lld\n",n+1);
            continue;
        }
        int p=find(n);
        printf("%lld\n",cal(n,p,0,0));

    }

    return 0;
}
