#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<set>
using namespace std;

#define maxm 105

int dp[maxm][4][4];
int fl[maxm][4][4],kas=1;
char s[maxm];

int cal(int len,int l,int r);
int getid(char ch){
    if(ch=='X') return 1;
    if(ch=='O') return 2;
    return 0;
}


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%s",s);

        int beg=0,last=0,c=0,ans=0;

        for(i=0;s[i];i++){ if(isalpha(s[i])) c++; }

        for(i=0;s[i];){
            beg=last=0;
            while(isalpha(s[i])){
                beg=getid(s[i]); i++;
            }
            k=0;
            while(s[i]=='.'){
                k++; i++;
            }
            if(isalpha(s[i])){
                last=getid(s[i]);
            }
            ans^=cal(k,beg,last);
            k=0;
        }
        ans^=cal(k,beg,last);

        c%=2; if(c) ans=!ans;
        if(ans) printf("Possible.\n");
        else printf("Impossible.\n");

        kas++;


    }

    return 0;
}


int cal(int len,int l,int r){

    if(!len) return 0;

    if(fl[len][l][r]==kas) return dp[len][l][r];
    fl[len][l][r]=kas;

    int i,j,ret=0;
    set<int>set1;
    for(i=1;i<=len;i++){
        for(j=1;j<=2;j++){
            if(i==1 && j==l) continue;
            if(i==len && j==r) continue;
            set1.insert(cal(i-1,l,j)^cal(len-i,j,r));
        }
    }

    while(set1.find(ret)!=set1.end()) ret++;

    return dp[len][l][r]=ret;
}
