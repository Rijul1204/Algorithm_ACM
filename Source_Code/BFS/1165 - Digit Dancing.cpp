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

#define maxm 50500
#define maxn 10
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
    int cost;
    int a[maxn];
};
map<int,int>vis_state;
int map_tot;

const int CN=8;

int a[maxn],dest;
bool sign[maxn],vis[maxm];

queue<node>q;

int bfs();
node build_right(node from,int d1,int d2);
node build_left(node frome,int d1,int d2);

void cpy_arr(int to[],int from[],int upto){
    for(int i=0;i<=upto;i++){
        to[i]=from[i];
    }
}
int hash_code(int a[]){
    int ret=a[1];
    for(int i=2;i<=CN;i++){
        ret=ret*10+a[i];
    }
    return ret;
}
int save(int n){
    if(!vis_state[n]){
        vis_state[n]=map_tot++;
    }
    return vis_state[n];
}
int save(node nd){
    return save(hash_code(nd.a));
}

void init(){
    int a[10];
    for(int i=1;i<=8;i++){
        a[i]=i;
    }
    dest=save(hash_code(a));
}

int is_prime(int n){

    if(n==2 || n==3 || n==5 || n==7 || n==11 || n==13 ) return 1;
    return 0;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        for(i=1;i<=8;i++){
            scanf("%d",&a[i]);
            if(a[i]>0) sign[a[i]]=1;
            else{
                a[i]=-a[i];
                sign[a[i]]=0;
            }
        }

		vis_state.clear();

        map_tot=1;
        init();

        printf("Case %d: %d\n",t++,bfs());

    }

    return 0;
}

// d1 will go-right of d2 ..
node build_right(node from,int d1,int d2){

    if(d1>d2){
        return build_left(from,d1,d2+1);
    }

    // here d1<d2

    node ret;

    ret.cost=from.cost+1;

    int i;

    for(i=1;i<d1;i++){
        ret.a[i]=from.a[i];
    }
    for(i=d1;i<d2;i++){
        ret.a[i]=from.a[i+1];
    }
    ret.a[d2]=from.a[d1];

    for(i=d2+1;i<=CN;i++){
        ret.a[i]=from.a[i];
    }

    return ret;
}

// d1 will go-left of d2 ..
node build_left(node from,int d1,int d2){

    if(d1<d2){
        return build_right(from,d1,d2-1);
    }

    // here d1 > d2

    node ret;

    ret.cost=from.cost+1;

    int i;

    for(i=1;i<d2;i++){
        ret.a[i]=from.a[i];
    }
    ret.a[d2]=from.a[d1];

    for(i=d2+1;i<=d1;i++){
        ret.a[i]=from.a[i-1];
    }
    for(i=d1+1;i<=CN;i++){
        ret.a[i]=from.a[i];
    }

    return ret;
}

int bfs(){

    int i,j,num_i,num_j;
    node s;
	s.cost=0;
    cpy_arr(s.a,a,CN);

    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();

    vis[save(s)]=1;

    q.push(s);
    while(!q.empty()){

        node curr=q.front(); q.pop();
		node tmp;

        if(save(curr)==dest){
			//printf("%d\n",save(curr));
			return curr.cost;
		}

        for(i=1;i<=8;i++){
            num_i=curr.a[i];

            for(j=1;j<=8;j++){
                num_j=curr.a[j];
                if(sign[num_i]==sign[num_j] || !is_prime(num_i+num_j)) continue;

                tmp=build_right(curr,i,j);
                int ind=save(tmp);
                if(!vis[ind]){
					vis[ind]=1;
					q.push(tmp);
				}

                tmp=build_left(curr,i,j);
                ind=save(tmp);
                if(!vis[ind]){
                    vis[ind]=1;
                    q.push(tmp);
				}

            }

        }
    }

    return -1;
}

