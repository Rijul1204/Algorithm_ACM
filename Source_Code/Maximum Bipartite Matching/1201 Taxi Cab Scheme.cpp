#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define maxm 550

vector<int>v[maxm];
int right[maxm],col[maxm],n,h[maxm],m[maxm],x1[maxm],y1[maxm],x2[maxm],y2[maxm];

int match(int n);
bool dfs(int s);

int main(){

    int i,j,k,l,test,t=1,t1,t2;

   // freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=1;i<=n;i++){
            v[i].clear();
            scanf("%d:%d %d %d %d %d",&h[i],&m[i],&x1[i],&y1[i],&x2[i],&y2[i]);
        }


        for(i=1;i<=n;i++){
            t1=h[i]*60+m[i];
            k=x1[i]-x2[i];
            l=y1[i]-y2[i];
            if(k<0) k*=-1; if(l<0) l*=-1;
            t=k+l;
            t1+=t;
           // printf("t1 %d \n",t1);
            for(j=i+1;j<=n;j++){
                 t2=h[j]*60+m[j];
                 k=x2[i]-x1[j];
                 l=y2[i]-y1[j];
                 if(k<0) k*=-1; if(l<0) l*=-1;
                 t=k+l;
               //  printf("%d %d %d\n",t,t1,t2);
                 if(t+t1<t2){
                    // printf("%d %d\n",i,j);
                     v[i].push_back(j);
                 }
            }
        }

        printf("%d\n",n-match(n));
    }

}

int match(int n){

    memset(right,-1,sizeof(right));
    memset(col,0,sizeof(col));
    int i,j,k,l;
    k=0;

    for(i=1;i<=n;i++){
        memset(col,0,sizeof(col));
        if(dfs(i)) k++;
    }
   // printf("k->%d\n",k);
    return k;
}

bool dfs(int s){

    if(col[s])return 0;

    col[s]=1;
    int i,j,k;

    for(j=0;j<v[s].size();j++){
        i=v[s][j];
        if(right[i]==-1){
            right[i]=s;
            return 1;
        }
        if(dfs(right[i])){
            right[i]=s;
            return 1;
        }
    }

    return 0;
}

