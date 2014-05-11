#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm (50)
#define ii long long int

char s[maxm];
int c1[30],len,req;
ii dp[30][maxm],dp1[50][50];

int print(int fst,ii num,int lst);
ii cal(int n,int k);
ii ncr(int n,int r);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    memset(dp1,-1,sizeof(dp1));

    while(test--){

        scanf("%s %d",s,&req);
        len=strlen(s); memset(c1,0,sizeof(c1));
        for(i=0;s[i];i++){
            c1[s[i]-'a']++;
        }
        int mark=0,flag=0,fl=0;

        for(i=0;i<26;i++){
            if(len%2&&!fl&&c1[i]%2){
                mark=i; fl=1; c1[i]/=2;
                continue;
            }
            if(c1[i]%2==0){
                c1[i]/=2;
                continue;
            }
            flag=1; break;

        }

		l=len;
        len/=2;

		printf("Case %d: ",t++);
        if(!flag){
			memset(dp,-1,sizeof(dp));
			ii maxx=cal(len,0);
			if(maxx<req){
				printf("XXX\n");
				continue;
			}
			if(print(0,req,l-1)){
				if(l%2){
					s[l/2]=mark+'a';
				}
				printf("%s\n",s);
			}
			else printf("XXX\n");
        }
        else printf("XXX\n");

    }


    return 0;
}

int print(int fst,ii num,int lst){

    if(fst>=lst) return 1;

    int i,j,flag=0;
    ii val,val1=0;

    for(i=0;i<26;i++){
        if(c1[i]<1) continue;
        c1[i]--;
        memset(dp,-1,sizeof(dp));
        val=cal(len-1,0);
        if(val1+val>=num){
            s[fst]=i+'a'; s[lst]=i+'a';
            len--;
            print(fst+1,num-val1,lst-1);
            flag=1; break;
        }
		val1+=val;
        c1[i]++;
    }

    return flag;
}

ii cal(int n,int k){

    if(n==0) return 1;
    if(n<0||k>=26) return 0;

    if(dp[n][k]!=-1) return dp[n][k];

    return dp[n][k]=ncr(n,c1[k])*cal(n-c1[k],k+1);

}

ii ncr(int n,int r){

    if(r>n) return 0;
    if(r==0||n==r) return 1;
    if(r==1) return n;
    if(dp1[n][r]!=-1) return dp1[n][r];

    return dp1[n][r]=(ncr(n-1,r)+ncr(n-1,r-1));

}
