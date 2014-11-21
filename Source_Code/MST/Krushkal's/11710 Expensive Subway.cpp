#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct edge{
	int u;
	int v;
	int w;
};

edge edges[179900];
string s1,s2;
map<string,int>m1;
int pre[1000];

bool comp(edge a,edge b){
	
	return a.w<b.w;
	
}

int find(int x){
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}



int main(){

	int i,j,k,l,n,m,start;

	//freopen("in.txt","r",stdin);
	
	while(scanf("%d %d",&n,&m)==2){
		
		if(!n&&!m) break;

		for(i=1;i<=n;i++){
			cin>>s1;
			m1[s1]=i;
			pre[i]=i;
		}
		for(i=0;i<m;i++){
			cin>>s1>>s2>>l;
			edges[i].u=m1[s1];
			edges[i].v=m1[s2];
			edges[i].w=l;
		}
		cin>>s1;
		edge temp;
        int flag=0;
		int min;

		for(i=0;i<m;i++){
			
			if(edges[i].u==m1[s1]||edges[i].v==m1[s1]){
				
				if(!flag){
					min=edges[i].w;
					temp=edges[i];
					edges[i]=edges[0];
					edges[0]=temp;
					flag=1;
				}
				
				else if(edges[i].w<min){
					min=edges[i].w;
					temp=edges[i];
					edges[i]=edges[0];
					edges[0]=temp;
				}
					
			}
		
		}
		if(m>0) sort(edges+1,edges+m,comp);

		int tot=0;
	
		for(i=0;i<m;i++){
		//	printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].w);
			int a=find(edges[i].u);
			int b=find(edges[i].v);
			if(a!=b){
				pre[a]=b;
				tot+=edges[i].w;
			}

		}
		int count1=0;

		for(i=1;i<=n;i++){
			if(pre[i]==i) count1++;
			if(count1>=2) break;
		}
		if(count1<2) printf("%d\n",tot);
		else printf("Impossible\n");		

	}

	return 0;

}
