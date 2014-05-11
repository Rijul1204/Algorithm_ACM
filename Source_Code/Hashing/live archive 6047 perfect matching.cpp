#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 1010
#define mod 1000000007LL
#define bb 131 // base...
#define ii long long int

int getid(char ch){
    return (ch-'a'+1);
}

char s[maxm];
int n;
ii p[maxm],hh1[maxm],rr1[maxm],len[maxm];

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    p[0]=1;
    for(i=1;i<=1000;i++){
        p[i]=p[i-1]*bb; //p[i]%=mod;
    }

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=0;i<n;i++){
            scanf("%s",s);
            len[i]=strlen(s);
            ii h1,r1;
            h1=r1=0;
            for(j=0;s[j];j++){
                h1=h1*bb+getid(s[j]);
                //h1%=mod;
                r1=r1+p[j]*getid(s[j]);
            }
            hh1[i]=h1; rr1[i]=r1;
        }

        int ans=0;

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j) continue;
                ii v1=hh1[i]*p[len[j]]+hh1[j]; //v1%=mod;
                ii v2=rr1[i]+p[len[i]]*rr1[j]; //v2%=mod;

                if(v1==v2) ans++;
            }
        }

        printf("Case #%d: %d\n",t++,ans);

    }


    return 0;
}