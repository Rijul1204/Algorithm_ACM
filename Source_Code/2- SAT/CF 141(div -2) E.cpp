/*
Name : Rashedul Hasan Rijul (silent_coder)
Algo : 2 - Sat
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Two_sat...........

#define maxm 1000


//  1- based.....
struct two_sat{
    int n,nn,m;
    vector<int>G[maxm],GT[maxm],DAG[maxm],C[maxm],topo; // G= graph.. GT= transpose graph.......
    int col[maxm],comp,comp_no[maxm],soln[maxm];
    // comp= total number component;
    // comp_no[i]= component no of node i
    // soln[i]= truth symbol of node i;
    two_sat(){}
    void init(){
        for(int i=0;i<=n+n;i++){
            G[i].clear();
            GT[i].clear();
            DAG[i].clear();
			C[i].clear();
        }
        topo.clear();
        memset(col,0,sizeof(col));
		memset(comp_no,0,sizeof(comp_no));
        memset(soln,-1,sizeof(soln));
		comp=0;
    }
    int inv(int no){
        if(no<=n) return no+n;
        return no-n;
    }
    void OR(int u,int v){
        G[inv(v)].push_back(u);
        G[inv(u)].push_back(v);
    }
    void AND(int u,int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void XOR(int u,int v){
        G[inv(v)].push_back(u);
        G[u].push_back(inv(v));
        G[inv(u)].push_back(v);
        G[v].push_back(inv(u));
    }
    void XNOR(int u,int v){
        G[u].push_back(v);
        G[v].push_back(u);
        G[inv(u)].push_back(inv(v));
        G[inv(v)].push_back(inv(u));
    }

    // Have to change for every problem ( problem  Dependent )
    void build_graph(){
        int u,v,op;
        nn=n+n;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&op);
            if(op==1) XNOR(u,v);
            else if(op==0) XOR(u,v);
        }
    }

    void make_reverse(){

        for(int i=1;i<=nn;i++){
            for(int j=0;j<G[i].size();j++){
                GT[G[i][j]].push_back(i);
            }
        }
    }
    int check_solution(){
        // Build  scc..........
        build_scc();

        for(int i=1;i<=n;i++){
            if(comp_no[i]==comp_no[inv(i)]) return 0;
        }
        return 1;

    }
    void find_solution(vector<int>&res){
        int i,j,i_p;
        res.clear();
        for(i=1;i<=comp;i++){
            if(soln[i]==-1){
                soln[i]=0;
                i_p=comp_no[inv(C[i][0])];
                soln[i_p]=1;
                for(j=0;j<C[i_p].size();j++){
                    if(C[i_p][j]<=n) res.push_back(C[i_p][j]);
                }
            }
        }
    }

    void build_dag(){
        int i,j;
        for(i=1;i<=nn;i++){
            for(j=0;j<G[i].size();j++){
                if(comp_no[i]==comp_no[G[i][j]]) continue;
                DAG[comp_no[i]].push_back(comp_no[G[i][j]]);
            }
        }
    }

    void build_scc(){
        make_reverse();
        int i;
        for(i=1;i<=nn;i++){
            if(!col[i]) dfs(i);
        }
        for(i=topo.size()-1;i>=0;i--){
            if(!comp_no[topo[i]]){
                scc(topo[i],++comp);
            }
        }
    }
	void dfs(int s){
		if(col[s]) return ;
		col[s]=1;

		for(int i=0;i<G[s].size();i++){
			dfs(G[s][i]);
		}
		topo.push_back(s);
	}
	void scc(int s,int comp){
	    if(comp_no[s]) return ;
	    comp_no[s]=comp;
		C[comp].push_back(s);

	    for(int i=0;i<GT[s].size();i++){
	        scc(GT[s][i],comp);
	    }
	}
};
two_sat T_sat;

//  finish..........

vector<int>res;


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    int n,m;

    while(scanf("%d",&n)==1){

        scanf("%d",&m);
        T_sat.n=n; T_sat.m=m;
        T_sat.init();
        T_sat.build_graph();
        int ans=T_sat.check_solution();
        if(ans){
            res.clear();
            T_sat.find_solution(res);
            printf("%d\n",res.size());
            for(i=0;i<res.size();i++){
                if(i) printf(" ");
                printf("%d",res[i]);
            }
            puts("");
        }
        else{
            printf("Impossible\n");
        }

    }

    return 0;
}



