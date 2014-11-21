#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define maxm 16
#define maxn (1<<16)
#define maxl 110
#define inf 1<<29

int on(int n,int k){
	return (n|(1<<k));
}
int off(int n,int k){
	return (n-(n&(1<<k)));
}
bool chck(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

struct node{
    int ind;
    char s[110];
};

int dp[maxm][maxn],pi[maxm*maxl],n,pre[maxm][maxn],order[110][maxm],len[maxm];
bool vis[maxm][maxn];
int mat[maxm][maxm];
char s[maxm][110];

int kmp(char t[],char p[]);
void prefix(char p[]);
int cal(int last,int mask);
void print(int last,int mask);
void init();
bool comp(node a,node b){
    if(strcmp(a.s,b.s)>0) return 0;
	return 1;
}


int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		memset(mat,0,sizeof(mat));
		init();


		memset(vis,0,sizeof(vis));

		printf("Case %d: ",t++);
		cal(n,0);
		print(n,0);
		printf("\n");



	}

	return 0;
}

int cal(int last,int mask){

	if(mask==(1<<n)-1) return  0;

	if(vis[last][mask]) return dp[last][mask];
	vis[last][mask]=1;

	int i1,i,k,j,l,l1,ret=inf,ret1,temp,mark=-1;

	for(i1=0;i1<n;i1++){
		i=i1;
		if(chck(mask,i)) continue;
        if(mat[last][i]>=len[i]){
			k=on(mask,i);
			ret1=cal(last,k);
		}
		else{
			k=on(mask,i);
			temp=len[i]-mat[last][i];
			ret1=temp+cal(i,k);
		}
		if(ret1<ret){
			ret=ret1;
			pre[last][mask]=i;
			mark=i;
		}
		else if(ret1==ret&&mark!=-1){
		    if(order[last][i]<order[last][mark]){
		        ret=ret1;
                pre[last][mask]=i;
                mark=i;
            }
        }
	}

	return dp[last][mask]=ret;

}

void init(){

    int i,j,k,l[20];
    node nodes[20];

    for(i=0;i<n;i++){
        len[i]=strlen(s[i]);
    }
	for(j=0;j<n;j++){
		strcpy(nodes[j].s,s[j]);
        nodes[j].ind=j;
	}
	sort(nodes,nodes+j,comp);
	for(j=0;j<n;j++){
        order[n][nodes[j].ind]=j;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			//if(i==j) continue;
            mat[i][j]=kmp(s[i],s[j]);
            if(mat[i][j]==len[j]) strcpy(nodes[j].s,"");
            else strcpy(nodes[j].s,s[j]+mat[i][j]);
            nodes[j].ind=j;
        }
        sort(nodes,nodes+j,comp);
        for(j=0;j<n;j++){
            order[i][nodes[j].ind]=j;
        }
    }

	//printf("shesh\n");

}

void print(int last,int mask){

	if(mask==(1<<n)-1) return ;

	int i=pre[last][mask],j,k;

	if(mat[last][i]>=len[i]){
		k=on(mask,i);
		print(last,k); return ;
	}
	int temp=len[i]-mat[last][i];
	for(j=len[i]-temp;j<len[i];j++){
		printf("%c",s[i][j]);
	}
	k=on(mask,i);
	print(i,k);

}

void prefix(char p[]){

	int m,q,k;
	m = strlen(p);
	pi[1] = k = 0;
	for(q=2;q<=m;q++){
		while(k>0 && p[k] != p[q-1]) k = pi[k];
		if(p[k] == p[q-1]) k++;
		pi[q] = k;
	}
}



int kmp(char t[],char p[]){

	int n=strlen(t);
	int m=strlen(p);
	prefix(p);
	int i,j,q;
	q = 0;
	for(i=0;i<n;i++){
		while(q > 0 && p[q]!=t[i]) q = pi[q];
		if( p[q] == t[i] ) q = q + 1;
		if(q == m ) return m;

	}
	return q;
}


