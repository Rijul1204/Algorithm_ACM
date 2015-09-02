/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2015-09-02
Algo Used   : BFS + Bitmask
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

#define maxm 21
#define maxn ((1<<maxm)+10)
#define inf (1000000001)
#define dd double
#define ii int

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n, ii k){ return (n | (1 << k)); }
ii off(ii n, ii k){ return (n - (n&(1 << k))); }
bool chck(ii n, ii k){ return (n&(1 << k)); }

dd mind(dd a, dd b){ if (a<b) return a;  return b; }
dd maxd(dd a, dd b){ if (a>b) return a;  return b; }


int n, m;
int par[maxn], mov[maxn], vis[maxn], kas = 1; // using kas variable so that we can avoid costly memset operation 
// Adjacency matrix (in Bitmask format) for each node. 
int adj[maxm + 23];
queue<int>q;

bool bfs(){

	/*
		We assume that monkey can be in i'th node if i'th of mask is set to 1.
	*/

	// Source = all bit set to 1 ..
	int source = ((1 << n) - 1);
	int dest = 0; // destination = all bit set to 0 . . .

	while (!q.empty()){
		q.pop();
	}

	q.push(source);
	vis[source] = kas;
	par[source] = source;

	while (!q.empty()){

		int mask = q.front(); q.pop();

		if (mask == 0) return true;

		// shooting at i'th node. . .
		for (int i = 0; i < n; i++){

			int n_mask = 0;
			// monkey at j'th node. . .
			for (int j = 0; j < n; j++){
				if (i == j || !chck(mask, j)) continue;
				n_mask |= (adj[j]); // generating new mask . . .
			}
			if (vis[n_mask] == kas) continue;
			vis[n_mask] = kas;   // marking n_mask node  . . 
			par[n_mask] = mask;  // reached (n_mask)th node from mask node . .
			mov[n_mask] = i;	 // reached (n_mask)th node by shooting at i'th node . .
			q.push(n_mask);
		}
	}
	
	// no solution found .
	return false;
}


int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while (scanf("%d %d", &n, &m) == 2){

		if (n == 0 && m == 0) break;

		memset(adj, 0, sizeof(adj));

		for (int i = 0; i < m; i++){
			scanf("%d %d", &k, &l);
			// Set bit for each adjacent node
			adj[k] = on(adj[k], l);
			adj[l] = on(adj[l], k);
		}

		kas++;

		if (!bfs()){
			puts("Impossible");
		}
		else{
			vector<int>ans;

			// generating path . . 
			int mask = 0;
			while (par[mask] != mask){
				ans.push_back(mov[mask]);
				mask = par[mask];
			}
			reverse(ans.begin(), ans.end());

			printf("%d:", ans.size());
			for (i = 0; i < ans.size(); i++){
				printf(" %d", ans[i]);
			}
			puts("");
		}

	}

	return 0;
}
