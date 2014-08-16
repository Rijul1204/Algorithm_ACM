#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

#define maxm 1000100
#define mod 1000000007LL
#define base 27 // base...
#define ii long long int

int getid(char ch){
    return ch-'a';
}

ii p[maxm],h[maxm];
int n;
char s[maxm];

ii gethash(int i,int j){
    ii ret=h[i]-p[j-i+1]*h[j+1];
    ret%=mod; if(ret<0) ret+=mod;
    return ret;
}
void print(int i,int j){

    for(int i1=i;i1<=j;i1++){
        printf("%c",s[i1]);
    }
    puts("");
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    p[0]=1;
    for(i=1;i<=15;i++){
        p[i]=p[i-1]*base;
        if(p[i]>=mod) p[i]%=mod;
    }

    while(scanf("%d",&n)==1){

        scanf("%s",s);
        l=strlen(s);
        h[l]=0;
        for(i=l-1;i>=0;i--){
            h[i]=getid(s[i])+(base*h[i+1]);
            if(h[i]>=mod) h[i]%=mod;
        }

        map<int,int>map1;
        int max1=0,piv=-1;
        for(i=0,j=i+n-1;j<l;i++,j++){
            ii now=gethash(i,j);
            map1[now]++;
            if(map1[now]>max1){
                max1=map1[now];
                piv=now;
            }
        }

        for(i=0,j=i+n-1;j<l;i++,j++){
            ii now=gethash(i,j);
            if(now==piv){
                print(i,j); break;
            }
        }


    }

    return 0;
}
