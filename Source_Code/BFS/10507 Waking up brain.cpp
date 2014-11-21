#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

#define inf 12345678

map<char,int>let;
vector<int>v[110];
queue<int>q;
int count1[100],col[100];
int d[100],n,m;
void bfs();

int main(){

	int i,j,k,l;
	char help[5],ch1,ch2,ch3,ch4,ch;
	char s[100];
	
//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		for(i=0;i<=n;i++) v[i].clear();
		scanf("%d",&m);
		let.clear();
		scanf("%s",s);
		let[s[0]]=1;
		let[s[1]]=2;
		let[s[2]]=3;
		k=4;
		for(i=1;i<=m;i++){
			scanf("%s",s);

			if(!let[s[0]]){
				let[s[0]]=k++;
			}
			if(!let[s[1]]){
				let[s[1]]=k++;
			}

			v[let[s[0]]].push_back(let[s[1]]);
			v[let[s[1]]].push_back(let[s[0]]);

		}

		bfs();

		int flag=0;
		int max=0;

		for(i=1;i<=n;i++){
			if(!col[i]||d[i]==-1){
				flag=1;
				break;
			}
			if(max<d[i]){
				max=d[i];
			}
		}
		
		if(flag) printf("THIS BRAIN NEVER WAKES UP\n");
		else printf("WAKE UP IN, %d, YEARS\n",max);

	}
	

	return 0;
}

void bfs(){

	int i,j,k,l;

	for(i=0;i<=n;i++){
		d[i]=-1;
		col[i]=0;
		count1[i]=0;
	}

	d[1]=d[2]=d[3]=0;
	col[1]=col[2]=col[3]=1;

	q.push(1); q.push(2); q.push(3);

	while(!q.empty()){

		i=q.front(); q.pop();

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(col[k]) continue;
			if(d[k]<d[i]+1){
				d[k]=d[i]+1;				
			}
			count1[k]++;
			if(count1[k]==3){
				col[k]=1;
				q.push(k);
			}

		}


	}

}



	



