#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
using namespace std;

int col[20100];
int state[20100],on,tw;
vector<int>v[20100];
map<int,int>num;
queue<int>q;
void bfs(int s);
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int flag;

int main(){

	int i,j,k,l,test,t=1,sum;
	int count1,n;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		scanf("%d",&n);
		num.clear();
		memset(col,0,sizeof(col));
		memset(state,0,sizeof(state));
		for(i=0;i<=20010;i++){
			v[i].clear();
		}

		count1=1;
		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&l);
			if(!num[k]) num[k]=count1++;
			if(!num[l]) num[l]=count1++;
			v[num[k]].push_back(num[l]);
			v[num[l]].push_back(num[k]);
		}
		flag=1;
		sum=0;

		for(i=1;i<count1;i++){
			
			if(!col[i]){
				on=tw=0;
				bfs(i);
				sum+=max(on,tw);
			}

		}

		printf("Case %d: %d\n",t++,sum);



	}


	return 0;
}

void bfs(int s){
	
	col[s]=1;
	state[s]=1;
	on++;
	q.push(s);
	int i,j,k,l;

	while(!q.empty()){

		i=q.front(); q.pop();

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(state[k]==state[i]) flag=0;
			if(!col[k]){
				state[k]=3-state[i];
				if(state[k]==1) on++;
				else tw++;
				col[k]=1;
				q.push(k);
			}

		}

	}

}