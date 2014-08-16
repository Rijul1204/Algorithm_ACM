/*
Author  : Rashedul Hasan Rijul ( Silent_coder) .
Problem : LOJ 1355 ( Game of CS ) .
Algo    : Green Hackenbush on Tree .
*/

#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 1010
#define ii long long int

vector<int>v[maxm],w[maxm];
int n;

int cal(int s,int pre);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=0;i<=n;i++){
            v[i].clear();
            w[i].clear();
        }

        for(i=1;i<n;i++){
            scanf("%d %d %d",&k,&l,&j);
            v[k].push_back(l);
            v[l].push_back(k);

            //j%=2;
            w[k].push_back(j);
            w[l].push_back(j);
        }

        printf("Case %d: ",t++);
        if(cal(0,0)) printf("Emily\n");
        else         printf("Jolly\n");

    }

    return 0;
}

int cal(int s,int pre){

    int i,ret=0;
    ii sum=0;

    for(i=0;i<v[s].size();i++){
        int k=v[s][i];
        if(k==pre) continue;
        if(w[s][i]!=1) ret^=(cal(k,s));
        else           ret^=(cal(k,s)+1);
        if(w[s][i]!=1) sum+=w[s][i];
    }
    ret^=(sum%2);

    return ret;
}
