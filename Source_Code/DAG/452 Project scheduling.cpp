#include<stdio.h>
#include<string.h>
#include<vector>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

#define maxm 35
#define inf 1<<27

vector<int>v[maxm],topo;
int d[maxm],p[maxm],col[maxm];
char s[3*maxm],temp[maxm];

void dfs(int s);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1,u,bl=0;

//	freopen("in.txt","r",stdin);
	scanf("%d",&test);
	gets(s);
	gets(s);

	while(test--){
		
		for(i=0;i<=30;i++){
			v[i].clear();
			p[i]=0;
			d[i]=-1;
		}
		topo.clear();
		
		while(gets(s)){	
			if(!s[0]) break;
			u=s[0]-'A'+1;
			for(i=1;s[i];i++){
				if(isdigit(s[i])){
					l=0;
					while(isdigit(s[i])){
						temp[l++]=s[i++];
					}
					temp[l]='\0';
					k=atoi(temp);
					p[u]=k;
					i--;
					continue;
				}
				if(isalpha(s[i])){
					k=s[i]-'A'+1;
					v[k].push_back(u);
				}
			}
		}

		memset(col,0,sizeof(col));

		for(i=1;i<=27;i++){
			if(!col[i]) dfs(i);
		}
		int ans=-1;

		for(j=topo.size()-1;j>=0;j--){
			i=topo[j];
			d[i]=maxi(d[i],p[i]);
			ans=maxi(ans,d[l]);
			for(k=0;k<v[i].size();k++){
				l=v[i][k];
				if(d[l]<d[i]+p[l]){
					d[l]=d[i]+p[l];
					ans=maxi(ans,d[l]);
				}
			}

		}
		if(bl) printf("\n");
		bl=1;

		printf("%d\n",ans);


	}


	return 0;
}

void dfs(int s){
	col[s]=1;

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(!col[k]) dfs(k);
	}

	topo.push_back(s);

}