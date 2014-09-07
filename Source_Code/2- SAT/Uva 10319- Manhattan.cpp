/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-31
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

#define maxm 2010
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

// Two_sat...........


//  1- based.....
struct two_sat{
    int n,nn;
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
        nn=n+n;
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
two_sat t_sat;

//  finish..........

int S,A,m;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d %d",&S,&A,&m);
        t_sat.n=S+A;
        t_sat.init();

        int s1,a1,s2,a2;
        for(i=1;i<=m;i++){
            scanf("%d %d %d %d",&s1,&a1,&s2,&a2);
            a1+=S,a2+=S;

			if(s1==s2 && a1==a2) continue;

            if(s1==s2){
                if(a1>a2){
                    s1=t_sat.inv(s1);
                }
                t_sat.OR(s1,s1);
                continue;
            }

            if(a1==a2){
                if(s1>s2){
                    a1=t_sat.inv(a1);
                }
                t_sat.OR(a1,a1);
                continue;
            }

            // Formula = (s1^a2)| (s2^a1) = (s1|s2)^(s1|a1)^(a2|s2)^(a2|a1)
            if(a1>a2){
                s1=t_sat.inv(s1);
                s2=t_sat.inv(s2);
            }
            if(s1>s2){
                a1=t_sat.inv(a1);
                a2=t_sat.inv(a2);
            }

			t_sat.OR(s1,s2);
			t_sat.OR(s1,a1);
			t_sat.OR(a2,s2);
			t_sat.OR(a2,a1);
        }

		if(t_sat.check_solution()) puts("Yes");
		else					   puts("No");

    }

    return 0;
}

