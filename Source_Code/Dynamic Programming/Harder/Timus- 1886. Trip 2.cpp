/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-09
Algo Used   : Dp + Graph( Tree)
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
#include<unordered_map>
#include <ctime>
using namespace std;

#define mx_cn 201
#define maxm 100100
#define maxn 920
#define inf (1000000009)
#define ii __int64

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

ii mini(ii a, ii b){
	if (a < b) return a;
	return b;
}

struct node{
	int v, t, f, p, d, mem_ind;
	node(){}
	node(int _v, int _t, int _f, int _p, int _d){
		v = _v, t = _t, f = _f, p = _p, d = _d;
	}
};

bool cmp(node a, node b){
	return a.t < b.t;
}

int n, m, cnt = 1;
vector<node>G[maxm];

double dp[maxm * 4];
int vis[maxm * 4], kas = 1;


// binary search for finding lowest flight index with it's Depart Time greater equal to tim . . 
int bs(vector<node> &v, ii tim){

	if (v.size() == 0) return 0;

	int lo = 0, hi = v.size() - 1;
	if (v[hi].t < tim) return hi + 1;
	if (v[lo].t >= tim) return lo;

	int mid;

	while (lo < hi){

		mid = lo + hi; mid /= 2;

		if (v[mid].t < tim){
			lo = mid + 1;
		}
		else{
			if (hi == mid){
				if (mid && v[mid - 1].t >= tim) return mid - 1;
				return mid;
			}
			hi = mid;
		}
	}

	return hi;
}

// Ind = node
// tim = Current Time.
double cal(int& ind, ii tim){

	if (ind == n) return tim;

	int ind1 = bs(G[ind], tim);

	if (ind1 >= G[ind].size()) return inf;

	int mem_ind = 0;
	mem_ind = G[ind][ind1].mem_ind;

	if (vis[mem_ind] == kas) return dp[mem_ind];
	vis[mem_ind] = kas;

	double ret = inf;

	for (int i = ind1; i < G[ind].size(); i++){

		if (i != ind1 && vis[G[ind][i].mem_ind] == kas){
			if (ret > dp[G[ind][i].mem_ind]) ret = dp[G[ind][i].mem_ind];
			break; // We already visited this node . so no need to move forward .  
		}

		double pr = (double)G[ind][i].p / 100.0;

		double ret1 = cal(G[ind][i].v, (ii)G[ind][i].t + (ii)G[ind][i].f); // normal flight

		if (ret1 > inf || iseq(ret1, inf)){
			vis[G[ind][i].mem_ind] = kas;
			dp[G[ind][i].mem_ind] = inf;
			continue;
		}

		double ret2 = cal(G[ind][i].v, (ii)((ii)G[ind][i].t + (ii)G[ind][i].f + (ii)G[ind][i].d)); // delay flight

		if (ret2 > inf || iseq(ret2, inf)){
			vis[G[ind][i].mem_ind] = kas;
			dp[G[ind][i].mem_ind] = inf;
			continue;
		}

		double ret3 = ret1*(1.0 - pr) + ret2*pr;

		if (ret3 < ret) ret = ret3;
		vis[G[ind][i].mem_ind] = kas;
		dp[G[ind][i].mem_ind] = ret3;
	}

	// Update all the expected time of flight . . .. 
	for (int i = G[ind].size() - 2; i >= ind1; i--){
		if (dp[G[ind][i + 1].mem_ind] < dp[G[ind][i].mem_ind]){
			dp[G[ind][i].mem_ind] = dp[G[ind][i + 1].mem_ind];
		}
	}

	return dp[mem_ind] = ret;
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);	

	scanf("%d %d", &n, &m);

	int a, b, tt, ff, pp, dd;

	for (i = 0; i <= n; i++){
		G[i].clear();
	}
	cnt = 1; // cnt for numbering each edge. . .
	kas++;   // for optimization of memoization ( although it's not neccessary for single case problem )

	for (i = 1; i <= m; i++){

		scanf("%d %d %d %d %d %d", &a, &b, &tt, &ff, &pp, &dd);

		G[a].push_back(node(b, tt, ff, pp, dd));
	}


	for (i = 0; i <= n; i++){
		sort(G[i].begin(), G[i].end(), cmp); // Sorting according to the depart time . . 
		for (j = 0; j < G[i].size(); j++){
			G[i][j].mem_ind = cnt++;
		}
	}

	int ind = 1, tim = 0;
	double ans = cal(ind, tim); // Dp call

	if (ans < inf){ 
		printf("%.8lf\n", ans);
	}
	else{ 
		puts("Fail");
	}

	return 0;
}