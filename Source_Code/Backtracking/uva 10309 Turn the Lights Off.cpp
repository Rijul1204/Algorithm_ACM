/*
Author : Rashedul Hasan Rijul ( Silent_coder ).
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

#define maxm 12
#define inf (1<<29)
#define ii int
#define cn 10

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

char test_name[100];
char grid[maxm][maxm];
int grid_bit[maxm];

int find_ans(int row1);
void toggle(int r,int c){

    int &row1=grid_bit[r-1];
    int &row2=grid_bit[r];
    int &row3=grid_bit[r+1];

    row2^=(1<<c);
    row1^=(1<<c);
    row3^=(1<<c);

    if(c>0) row2^=(1<<(c-1));
    if(c<9) row2^=(1<<(c+1));
}

void print_row(int bit){

    for(int i=0;i<10;i++){
        if(chck(bit,i)) printf("O");
        else            printf("#");
    }
    puts("");
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    while(scanf("%s",test_name)==1){

        if(strcmp(test_name,"end")==0) break;

        for(i=1;i<=10;i++){
            scanf("%s",grid[i]);
            grid_bit[i]=0;
            for(j=0;grid[i][j];j++){
                if(grid[i][j]=='O') grid_bit[i]=on(grid_bit[i],j);
            }
            //print_row(grid_bit[i]);
        }

        int ans=105;
        for(int mask=0;mask<(1<<10);mask++){
            ans=mini(ans,find_ans(mask));

            /*for(i=1;i<=10;i++){
                print_row(grid_bit[i]);
            }
            puts("");
            puts("");*/

        }

        if(ans>100) ans=-1;
        printf("%s %d\n",test_name,ans);
    }


    return 0;
}

int cal(int row){

    if(row>cn){
       if(grid_bit[row-1]) return inf;
       return 0;
    }

    int i,mask=grid_bit[row-1],ret=0;

    for(i=0;i<10;i++){
        if(chck(mask,i)){
            ret++;
            toggle(row,i);
        }
    }

    ret+=cal(row+1);

    for(i=0;i<10;i++){
        if(chck(mask,i)){
            toggle(row,i);
        }
    }

    return ret;

}

int find_ans(int mask){

    int tmp1=grid_bit[1];
    int i,ret=0;

    for(i=0;i<10;i++){
        if(chck(mask,i)){
            ret++;
            toggle(1,i);
        }
    }

    ret+=cal(2);

    for(i=0;i<10;i++){
        if(chck(mask,i)){
            toggle(1,i);
        }
    }

    return ret;
}
