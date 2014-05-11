#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define inf 1199999

vector<int>v[1000];
queue<int>q;
int col[1000],state[1000];
int num[4];

void set(int n);
bool bfs(int s);
int mini(int a,int b){
	if(a<b) return a;
	return b;

}

int main(){
	
	int i,j,k,l,test,n,m;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d",&n,&m);
		set(n);
		for(i=0;i<=n;i++) v[i].clear();
		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			v[l].push_back(k);
		}
		if(n==1){
			printf("1\n");
			continue;
		}
		int valid;
		int sum=0;
		for(i=0;i<n;i++){
			if(v[i].size()==0){
				sum++;
				continue;
			}
			if(!col[i]){
				valid=bfs(i);
				if(valid){
					sum+=mini(num[1],num[2]);
					num[1]=0; num[2]=0;
				}
			}
			if(!valid) break;
		}
		
		if(valid){
			printf("%d\n",sum);
		}
		else printf("-1\n");
		
		
	}
	
	
	
	return 0;
	
}

void set(int n){
	
	for(int i=0;i<=n;i++){
		col[i]=state[i]=0;
	}
	num[0]=num[1]=num[2]=0;
	
}


bool bfs(int s){
	
	while(!q.empty()) q.pop();
	col[s]=1;
	state[s]=1;
	num[1]++;
	
	int i,j,k,l;
	
	q.push(s);
	
	
	while(!q.empty()){
		
		i=q.front(); q.pop();
		col[s]=1;
		
		for(j=0;j<v[i].size();j++){
			k=v[i][j];

			if(state[i]==state[k]) return false;

			if(col[k]) continue;

			state[k]=3-state[i];
			num[3-state[i]]++;
			col[k]=1;
			q.push(k);

			
		}
		
	}
	
	
	return true;
	
}


