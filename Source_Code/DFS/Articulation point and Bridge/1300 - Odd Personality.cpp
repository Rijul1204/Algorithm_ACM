#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<set>
using namespace std;

#define maxm 10100

set<int>bridge[maxm];
vector<int>v[maxm];
// col= coloring of node, low= low value of node, d=discovery time of node , tim= visiting time ....(current);
// state= for  bicoloring  ....
int col[maxm],low[maxm],d[maxm],tim,state[maxm];
queue<int>q;
void dfs(int s,int pre);
int bfs(int s);

int main(){

    int i,j,k,l,test,t=1;
    int n,m;

  //  freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);

        //initialization.......
        for(i=0;i<=n;i++){
            v[i].clear(); bridge[i].clear();
        }
        memset(col,0,sizeof(col)); memset(low,0,sizeof(low)); memset(d,0,sizeof(d));
        tim=0;
        ////******/////

        for(i=1;i<=m;i++){
            scanf("%d %d",&k,&l);
            v[k].push_back(l);
            v[l].push_back(k);
        }
        for(i=0;i<n;i++){
            if(!col[i]) dfs(i,i);
        }
        memset(col,0,sizeof(col));
        int ans=0;
        for(i=0;i<n;i++){
            if(!col[i]) ans+=bfs(i);
        }
        printf("Case %d: %d\n",t++,ans);

    }

    return 0;
}

int bfs(int s){

    int i,j,k,ret=0,flag=1;

    while(!q.empty()) q.pop();

    col[s]=1; state[s]=1; ret++;

    q.push(s);
    while(!q.empty()){

        i=q.front(); q.pop();

        for(j=0;j<v[i].size();j++){
            k=v[i][j];
            if(bridge[i].find(k)!=bridge[i].end()) continue;
            if(col[k]){
                 if(state[i]==state[k]) flag=0;
            }
            else{
                col[k]=1; state[k]=3-state[i];
                q.push(k); ret++;
            }
        }
    }
    if(ret==1) flag=1;
    if(!flag) return ret;
    return 0;
}

void dfs(int s,int pre){

    col[s]=1;
    low[s]=d[s]=tim++;

    int i,j,k;

    for(i=0;i<v[s].size();i++){
        k=v[s][i];

        if(col[k]==1&&k!=pre){
            if(d[k]<low[s]) low[s]=d[k];
            continue;
        }
        if(!col[k]){
            dfs(k,s);
            if(low[s]>low[k]) low[s]=low[k];
			if(d[s]<low[k]){
				bridge[s].insert(k);
				bridge[k].insert(s);				
			}
        }
    }
}
