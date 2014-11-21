#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

#define pi acos(-1.0)
#define inf (1<<28)
#define eps 1e-9
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define isEq(a,b) (fabs(a-b)<eps)
#define  ii __int64

int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};

vector<int>v[1000];
int disco[1000],low[1000],time1,col[1000],flag[1000],num=0;

void set(int n);
int dfs(int s,int no);

int main(){

	int i,j,k,l,ret,ans,e,n;
	char dum,input[20003],temp[20],help[10];

  // freopen("in.txt","r",stdin);
	

	while(scanf("%d",&n)==1&&n){

		for(i=0;i<=n;i++) v[i].clear();

		gets(help);
		set(n);
		
		while(1){
			
			gets(input);
			k=0;

			if(isdigit(input[k])){
				l=0;
				while(isdigit(input[k])){
					temp[l++]=input[k++];
				}
				temp[l]='\0';
				i=atoi(temp);
				
			}
			if(i==0) break;

			for(;input[k];k++){
				if(isdigit(input[k])){
					l=0;
					while(isdigit(input[k])){
						temp[l++]=input[k++];
					}
					k--;
					temp[l]='\0';
					j=atoi(temp);
					v[i].push_back(j);
					v[j].push_back(i);

				}
				if(!input[k]) break;

			}
		}

//		for(i=1;i<=n;i++){
//			printf("%d-> ",i);
//			for(j=0;j<v[i].size();j++) printf("%d ",v[i][j]);
//			printf("\n");
//		}

		if(dfs(1,0)>1) flag[1]=1;
		else flag[1]=0;
	
		ans=0;

		for(i=1;i<=n;i++){
		//	printf("%d %d\n",disco[i],low[i]);
			if(flag[i]){
				ans++;
			}
		}

		printf("%d\n",ans);


	}


	return 0;

}

void set(int n){

	int i,j;

	for(i=0;i<=n;i++){
		disco[i]=0;
		low[i]=0;
		flag[i]=0;
		col[i]=0;
		
	}
	time1=1;
	num=0;

}

int dfs(int s,int no){

	int i,j,k,l;
	col[s]=1;
	disco[s]=time1++;
	low[s]=disco[s];

	for(i=0;i<v[s].size();i++){
	
		int temp=v[s][i];
		
		if(col[v[s][i]]==1){
			if(low[s]>disco[v[s][i]]) low[s]=disco[v[s][i]];
		}
		
		else if(!col[v[s][i]]){
			
			no++;
			l=dfs(v[s][i],0);
			
			if(low[v[s][i]]<low[s]) low[s]=low[v[s][i]];
			if(low[v[s][i]]>=disco[s]){
				flag[s]=1;
			}
		}
	}

	col[s]=2;

	return no;

}

