/*
Author : Rashedul Hasan Rijul ( Silent_coder ).
Algo   : Hashing.
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 2015
#define inf (1<<30)
#define ii __int64
#define mod 1000000007
#define base 33 // base...

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n,ii k){ return (n|(1<<k)); }
ii off(ii n,ii k){ return (n-(n&(1<<k))); }
bool chck(ii n,ii k){ return (n&(1<<k)); }

ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

char s[maxm],beg[maxm],endd[maxm];
ii poww[maxm];
ii hash_s[maxm],hash_beg[maxm],hash_end[maxm];

void init_power(ii p[],int n){

    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*(ii)base;
        if(p[i]>=mod) p[i]%=mod;
    }
}

int getid(char ch){
    return ch-'a'+1;
}

void init_hash(char *s,ii h[]){

    int len=strlen(s);
    h[len]=0;
    for(int i=len-1;i>=0;i--){
        h[i]=getid(s[i])+(base*h[i+1]);
        if(h[i]>=mod) h[i]%=mod;
    }
}

ii get_hash(ii h[],int i,int j){
    ii ret=h[i]-poww[j-i+1]*h[j+1];

    if(ret>=mod || ret<0)ret%=mod;
    if(ret<0) ret+=mod;

    return ret;
}

map<ii,int>mapped_ind;

int main(){

    int i,j,k,l;
    int len_beg,len_end,len_s;
    ii h_beg,h_end;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    init_power(poww,maxm-5);

    scanf("%s",s);
    len_s=strlen(s);
    init_hash(s,hash_s);

    scanf("%s",beg);
    len_beg=strlen(beg);
    init_hash(beg,hash_beg);
    h_beg=get_hash(hash_beg,0,len_beg);

    scanf("%s",endd);
    len_end=strlen(endd);
    init_hash(endd,hash_end);
    h_end=get_hash(hash_end,0,len_end);


    int from_beg,from_end,ans=0;

    for(int len=1;len<=len_s;len++){
        if(len_beg>len || len_end>len) continue;
        mapped_ind.clear();

        for(i=0,j=i+len-1;j<len_s;i++,j++){
            int to_beg=(i+(len_beg-1));
            if(get_hash(hash_s,i,to_beg)!=h_beg) continue;

            int from_end=(j-(len_end-1));
            if(get_hash(hash_s,from_end,j)!=h_end) continue;

            ii now=get_hash(hash_s,i,j);
            //now*=(ii)(j-i+1);

            if(!mapped_ind[now]){
               mapped_ind[now]=1;
               ans++;
            }
        }
    }

    printf("%d\n",ans);

	return 0;
}

