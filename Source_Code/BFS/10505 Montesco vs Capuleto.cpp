#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

#define maxm 6000

vector<int>v[maxm];
queue<int>q;
int col[maxm],state[maxm],count1,count2;
bool bfs(int s);

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,n;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=0;i<=1000;i++) v[i].clear();
	
		for(i=1;i<=n;i++){
			scanf("%d",&l);
			for(k=1;k<=l;k++){
				scanf("%d",&j);
				if(j>n) continue;
				//if(i==j) continue;
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}

		memset(col,0,sizeof(col));
		memset(state,0,sizeof(state));

		int ans=0;

		for(i=1;i<=n;i++){
			if(col[i]==0){
				count1=0; count2=0;
				if(bfs(i)==1){
					ans+=maxi(count1,count2);
				}
			}
		}

		printf("%d\n",ans);
	
	}

	return 0;
}

bool bfs(int s){

	while(!q.empty()) q.pop();

	int i,j,k,l,flag;
	col[s]=1;
	state[s]=1;
	count1++;

	flag=1;
	
	q.push(s);

	while(!q.empty()){

		i=q.front();
		q.pop();

		for(k=0;k<v[i].size();k++){
			j=v[i][k];

			if(col[j]==0){
				col[j]=1;
			    state[j]=3-state[i];
				if(state[j]==1) count1++;
			    else count2++;
				q.push(j);

			}
			
			else if(state[j]==state[i]) flag=0;
	
		
		}


	}

	return flag;

}
