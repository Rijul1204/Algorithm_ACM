/*
Author : Rashedul Hasan Rijul ( Silent_coder ).
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 5
#define inf (1<<29)
#define ii int

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

struct node{
    int puzzle[maxm][maxm];
};

node curr_node;

int puzzle[maxm][maxm],final_pos[maxm][maxm];
string solution;
char soln[60];

int posx[]={4,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4};
int posy[]={4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};

int dirx[]={0,-1,1,0};
int diry[]={-1,0,0,1};

char move[]="LUDR";


void construct_final();
pii find_pos(int puzzle[maxm][maxm],int pos);

int nr_of_inversion(int puzzle[maxm][maxm]);
bool is_solvable(int puzzle[maxm][maxm]);

int ida_star(int puzzle[maxm][maxm]);
int ida_search(pii zero,int bound,int d);
int heuristic();

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    construct_final();

    scanf("%d",&test);

    while(test--){

        for(i=1;i<=4;i++){
            for(j=1;j<=4;j++){
                scanf("%d",&puzzle[i][j]);
            }
        }

        //printf("Case %d: ",t++);
        if(is_solvable(puzzle) && ida_star(puzzle)){
            cout << solution << endl;
        }
        else{
            puts("This puzzle is not solvable.");
        }

    }

    return 0;
}

int ida_star(int puzzle[maxm][maxm]){

    int i,j;
    node root;

    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            root.puzzle[i][j]=puzzle[i][j];
        }
    }

    curr_node=root;

    int bound=mini(50,heuristic());

    solution="";
    while(true){
        curr_node=root;
        pii zero=find_pos(root.puzzle,0);
        int next_bound=ida_search(zero,bound,0);
        if(next_bound<=bound) return 1;
        next_bound=mini(55,next_bound);
        //if(next_bound<=bound) break;
        bound=next_bound;
    }

    return 1;
}

int ida_search(pii pos_zero,int bound,int d){

    int f=heuristic();
    if(f+d>bound) return f+d;

    if(!f){
        if(solution.size()==0 || solution.size()>d+1){
            soln[d]=0;
            solution=soln;
        }
        return f;
    }

    int ret=-1,x,y;

    for(int i=0;i<4;i++){

        if(d && soln[d-1]==move[3-i]){
            continue;
        }

        x=dirx[i],y=diry[i];

        pii pos=pos_zero;

        pii new_pos=mp(pos.uu+x,pos.vv+y);

        if(new_pos.uu<1 || new_pos.uu>4 || new_pos.vv<1 || new_pos.vv>4){
            continue;
        }
        swap(curr_node.puzzle[pos.uu][pos.vv],curr_node.puzzle[new_pos.uu][new_pos.vv]);

        soln[d]=move[i];

        int ret1=ida_search(new_pos,bound,d+1);

        if(!ret1) return ret1;

		if(ret==-1) ret=ret1;
		ret=mini(ret,ret1);

		swap(curr_node.puzzle[pos.uu][pos.vv],curr_node.puzzle[new_pos.uu][new_pos.vv]);
    }

	return ret;
}

int heuristic(){

    int i,j,ret=0;

    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            int now=curr_node.puzzle[i][j];
            if(!now) continue;
            ret+=(abs(posx[now]-i));
            ret+=(abs(posy[now]-j));
        }
    }

    return ret;
}


pii find_pos(int puzzle[maxm][maxm],int pos){

    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(puzzle[i][j]==pos) return mp(i,j);
        }
    }
    return mp(-1,-1);
}

int nr_of_inversion(int puzzle[maxm][maxm]){

    int ret=0;
    int i,j,arr[maxm*maxm],tot=1;

    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            arr[tot++]=puzzle[i][j];
        }
    }

    for(i=1;i<tot;i++){
        for(j=i+1;j<tot;j++){
            if(!arr[i] || !arr[j]) continue;
            if(arr[i]>arr[j]) ret++;
        }
    }

    return ret;
}

bool is_solvable(int puzzle[maxm][maxm]){

    int n=nr_of_inversion(puzzle);
    int e=find_pos(puzzle,0).uu; // finding row containing 0

    //printf("%d %d\n",n,e);

    if( (n+e) % 2==0 ) return true;
    return false;

}

void construct_final(){

    int i,j;

    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            final_pos[i][j]=(i-1)*4+j;
        }
    }
    final_pos[4][4]=0;
}
