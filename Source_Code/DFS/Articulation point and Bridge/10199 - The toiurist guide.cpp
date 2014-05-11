#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;


map<string,int>city;
map<int,string>city1;
vector<int>v[1100];

int col[1000],dis[1000],low[1000],num[1000],flag[1000];
int node,edge,count1;
string out[1000];

void set(int n);
void dfs(int s,int root,int pre,int deep);

bool comp(string a,string b){
	return a<b;

}
int main(){

	int i,j,k,l,count1,t=1;
	bool blank=false;
	char s[11000],s1[11000],s2[11000];

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&node)&&node){

		set(node);
		city1.clear();city.clear();
		for(i=0;i<=node;i++) v[i].clear();

		for(i=1;i<=node;i++){
			scanf("%s",s);
			city[s]=i;
			city1[i]=s;
		}
		scanf("%d",&edge);

		for(i=1;i<=edge;i++){
			scanf("%s %s",s1,s2);
			v[city[s1]].push_back(city[s2]);
			v[city[s2]].push_back(city[s1]);
		}

		for(i=1;i<=node;i++){
			if(!col[i]){
				dfs(i,i,-1,0);
				if(num[i]>1) flag[i]=1;
			}
		}
		
		count1=0;
		for(i=1;i<=node;i++){
			if(flag[i]==1){
				out[count1++]=city1[i];
			}
		}
		sort(out,out+count1,comp);

		if(blank) printf("\n");
		blank=true;

		printf("City map #%d: %d camera(s) found\n",t++,count1);
		for(i=0;i<count1;i++) cout<<out[i]<<endl;		


	}

	return 0;
}

void set(int n){

	for(int i=0;i<=n;i++){
		col[i]=low[i]=dis[i]=num[i]=flag[i]=0;
	}

}

void dfs(int s,int root,int pre,int deep){

	col[s]=1;
	dis[s]=deep;
	low[s]=dis[s];

	for(int i=0;i<v[s].size();i++){
		int temp=v[s][i];
		if(col[temp]==1&&temp!=pre){
			if(low[s]>dis[temp]) low[s]=dis[temp];
		}
		else if(!col[temp]){
			num[s]++;
			dfs(temp,root,s,deep+1);
			if(low[temp]<low[s]) low[s]=low[temp];
			if(low[temp]>=dis[s]&&s!=root){
				flag[s]=1;
			}
		}
	}

	col[s]=2;

}

