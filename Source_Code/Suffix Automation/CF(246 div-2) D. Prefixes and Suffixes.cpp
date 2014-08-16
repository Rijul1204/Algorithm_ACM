/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-07.
Algo        : Suffix-Automation.
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

#define maxm 200010
#define inf (1<<29)
#define ii __int64

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

int n;
char s[maxm];

// Suffix-Automation

struct state {
	int len, link;
	bool suffix;
	ii count;
	map<char,int> next;
};

const int MAXLEN = maxm+2;
state st[MAXLEN*2];
int sz, last;
pair<int, int> sorter[MAXLEN * 2 + 10];

inline void sa_init() {
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	st[0].count = 0;
	st[0].suffix=0;
	++sz;
}

inline void sa_extend (char c) {

	int cur = sz++;
	st[cur].len = st[last].len + 1;
	st[cur].suffix=0;
	st[cur].count=1;

	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
//  Suffix-Automation End. ..

void post_process(){

    int i;

    for(i=0;i<sz;i++){
        sorter[i]=mp(st[i].len,i);
    }
    sort(sorter,sorter+sz);

    for(i=sz-1;i>=0;i--){
        int ind=sorter[i].vv;
        st[st[ind].link].count+=st[ind].count;
    }

    st[last].suffix=1;

    int p;
    for(p=last; p>0 ; p=st[p].link){
        st[p].suffix=1;
    }
}

vector<pii>ans;

void cal(char *s){

    int i;

    int curr_st=0;
    for(i=0;s[i];i++){

        while (curr_st && !st[curr_st].next.count(s[i])) {
            curr_st = st[curr_st].link;
        }
        if (st[curr_st].next.count(s[i])) {
            curr_st = st[curr_st].next[s[i]];
        }

        if(curr_st && st[curr_st].suffix){
            ans.push_back(mp(i+1,st[curr_st].count));
        }
    }
}

int main(){

    int i,q;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%s",s);

    sa_init();

    for(i=0;s[i];i++){
        sa_extend(s[i]);
    }
    post_process();

    cal(s);

    printf("%d\n",ans.size());

    for(i=0;i<ans.size();i++){
        printf("%d %d\n",ans[i].uu,ans[i].vv);
    }

    return 0;
}
