#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<ctype.h>
using namespace std;

map<string,int>name;
vector<int>v[10000];
queue<int>q;
char s[112100];
int dis[11000],col[11000],count1;
int names[11100],ind;
char temp[111000];

void bfs(int s);

int main(){

	int i,j,k,l,test,n,m,koma,t=1;
	

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		name.clear();

		scanf("%d %d",&m,&n);
		gets(s);
		count1=1;

		for(i=1;i<=m;i++){
			ind=0;
			gets(s);
			for(j=0;s[j];j++){
				if(s[j]==':') break;
				koma=0;
				if(isalpha(s[j])){
					l=0;
					while(1){
						if(s[j]==':') break;				
						if(s[j]==',') koma++;
						if(koma==2) break;
						temp[l++]=s[j++];
					}
					temp[l]='\0';
					j--;
					if(name[temp]==0) name[temp]=count1++;
				    names[ind++]=name[temp];
				}
				if(s[j]==':') break;
				
			}
			for(k=0;k<ind;k++){
				for(l=0;l<ind;l++){
					if(k==l) continue;
					v[names[k]].push_back(names[l]);
					v[names[l]].push_back(names[k]);
				}
			}
		}

		for(i=0;i<=count1;i++){
		dis[i]=-1;
		col[i]=0;
		}
		
		bfs(name["Erdos, P."]);

		printf("Scenario %d\n",t++);

		for(i=1;i<=n;i++){
			gets(s);
			for(j=0;s[j];j++){
				printf("%c",s[j]);
			}
			if(name[s]==0) printf(" infinity\n");
			else if(dis[name[s]]==-1) printf(" infinity\n");
			else printf(" %d\n",dis[name[s]]);

		}
		for(i=0;i<=count1;i++) v[i].clear();




	}


	return 0;
}

void bfs(int s){

	int i,j,k,l;

	
	dis[s]=0; col[s]=1;
	q.push(s);

	while(!q.empty()){

		i=q.front(); q.pop();

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(col[k]==1) continue;

			col[k]=1;
			dis[k]=dis[i]+1;
			q.push(k);
		}

	}

}



