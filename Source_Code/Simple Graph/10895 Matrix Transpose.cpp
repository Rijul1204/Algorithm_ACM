#include<stdio.h>
#include<vector>
using namespace std;

vector<int>v[11000],vt[11000],in[11000],indt[11000];
int ind[11000];

int  main(){

	int i,j,k,l,row,col,rowt,colt,n;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&row,&col)==2){

		if(row>col) k=row; 
		else k=col;
		for(i=0;i<=k+2;i++){
			v[i].clear();
			vt[i].clear();
			in[i].clear();
			indt[i].clear();
		}

		for(i=1;i<=row;i++){
			scanf("%d",&n);
			for(j=1;j<=n;j++){
				scanf("%d",&k);
				ind[j]=k;
				in[i].push_back(k);
				indt[k].push_back(i);
			}
			for(j=1;j<=n;j++){
				scanf("%d",&k);
				v[i].push_back(k);
				vt[ind[j]].push_back(k);
			}

		}

		printf("%d %d\n",col,row);
		
		for(i=1;i<=col;i++){
			printf("%d",vt[i].size());
			for(j=0;j<vt[i].size();j++){
				printf(" %d",indt[i][j]);
			}
			printf("\n");
			for(j=0;j<vt[i].size();j++){
				if(j>0) printf(" ");
				printf("%d",vt[i][j]);
			}
			printf("\n");
		}


	}

	return 0;
}

