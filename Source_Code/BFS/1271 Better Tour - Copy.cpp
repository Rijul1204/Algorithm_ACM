#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

#define maxm 51100
#define inf 1<<28


queue<int>q;
vector<int>v[maxm];
map<int,int>num,num1;

int n,m,d[maxm],col[maxm],a[maxm],c,pre[maxm];

bool comp(int a,int b){
	return a<b;
}

void bfs(int s);
void print(int x);

int main(){

	int i,j,k,l,test,t=1;
	
	//freopen("in.txt","r",stdin);

	scanf("%d",&test);
	
	while(test--){
		
		for(i=0;i<=maxm-5;i++){
			v[i].clear();
		}

		scanf("%d",&n);
		num.clear();
		num1.clear();
		c=1;
		
		scanf("%d",&a[1]);
		num1[c]=a[1];
		num[a[1]]=c++;


		for(i=2;i<=n;i++){
			scanf("%d",&a[i]);
		/*	if(!num[a[i]]){
				num1[c]=a[i];
				num[a[i]]=c++;				
			}
		*/
			v[a[i-1]].push_back(a[i]);
			v[a[i]].push_back(a[i-1]);
		}

		for(i=0;i<=maxm-5;i++){
			sort(v[i].begin(),v[i].end());
		}

		bfs(a[1]);

		l=a[n];

		printf("Case %d:\n",t++);
		print(pre[l]);
		printf("%d\n",l);


	}

}

void print(int x){
	if(x==-1) return ;
	print(pre[x]);
	printf("%d ",x);
}

void bfs(int s){

	int i,j,k,l;
	
	memset(d,-1,sizeof(d));
	memset(col,0,sizeof(col));
	memset(pre,-1,sizeof(pre));

	q.push(s);
	col[s]=1;

	while(!q.empty()){

		i=q.front(); q.pop();

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(!col[k]){
				d[k]=d[i]+1;
				pre[k]=i;
				col[k]=1;
				q.push(k);
			}
		}

	}

}