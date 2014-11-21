#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 51010
#define ii int

int pi[maxm],pre[5][maxm];
ii num[4][maxm],dp1[maxm],dp2[maxm];
char s[maxm],s2[maxm],s3[maxm],sinv[maxm];

void cal1(char s[],char p[]);
void process(char s[],int fl);
ii cal(char s[],char p[]);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%s",s);
        scanf("%s",s2);

        l=strlen(s2); j=0;
        for(i=l-1;i>=0;i--){
            s3[j++]=s2[i];
        }
        s3[j]='\0';
        l=strlen(s); j=0;
        for(i=l-1;i>=0;i--){
            sinv[j++]=s[i];
        }
        sinv[j]='\0';

        process(s2,1); process(s3,2);
        cal1(s,s2);
        printf("Case %d: %d\n",t++,cal(sinv,s3));
        /*
        for(i=0;s[i];i++){
            printf("%d ",dp1[i+1]);
        }
        printf("\n"); */

    }

    return 0;

}

ii cal(char s[],char p[]){

    int i,j,k,l,n,m;
    ii ret=0;
	n=strlen(s); m=strlen(p);
	k=0;

	for(i=1;i<=n;i++){
		while(k>0 && s[i-1]!=p[k]) k=pre[2][k];
		if(s[i-1]==p[k]) k++;
		if(k==m) k=pre[2][k];
		ret+=(num[2][k]*dp1[n-i]);

	}
	return ret;
}

void cal1(char s[],char p[]){

	int i,j,k,l,n,m,ret=0;
	n=strlen(s); m=strlen(p);
	k=0; dp1[0]=0;

	for(i=1;i<=n;i++){
		while(k>0 && s[i-1]!=p[k]) k=pre[1][k];
		if(s[i-1]==p[k]) k++;
		if(k==m){
			k=pre[1][k];
		}
		dp1[i]=num[1][k];

	}

}

void process(char p[],int fl){

	int i,j,k,l;
	num[fl][0]=0;
	for(i=0;p[i];i++){
	    num[fl][i+1]=1;
	}

	l=strlen(p);
	pre[fl][1]=0;
	k=0;

	for(i=2;i<=l;i++){
		while(k>0 && p[k]!=p[i-1]) k=pre[fl][k];
		if(p[k]==p[i-1]) k++;
		num[fl][i]+=num[fl][k];
		pre[fl][i]=k;
	}

}
