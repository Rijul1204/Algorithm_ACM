#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define ii long long int
#define inf 1<<28
#define maxm 30
#define valid k>0&&l>0&&k<=n&&l<=n&&d[temp.lev+1][c][k][l]>temp.cost+mat[i][j]


struct node{
	int x,y,cost,lev;	
};

bool operator<(const node &a,const node &b){
	if(a.cost==b.cost) return a.lev>b.lev;
	return a.cost>b.cost;
}
priority_queue<node>pq;

int mat[maxm][maxm];
int d[30][10][maxm][maxm],n,f,tim,d1[maxm][maxm];

void dij(node s,int c);

int main(){
	
	int i,j,k,l,test,t=1,c=1;
	
	//freopen("in.txt","r",stdin);
	
	while(scanf("%d %d %d",&n,&f,&tim)==3){
		
		if(!n&&!f&&!tim) break;
		
		tim++;
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		
		c=1;		
		for(i=1;i<=f;i++){
			scanf("%d %d",&k,&l);
			node temp;
			temp.x=k+1; temp.y=l+1; temp.cost=0;
			dij(temp,c++);			
		}
		
		ii ans;
		int markx,marky;
		ans=inf;
		int add;
		ii tot=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				tot=0;
				for(k=1;k<=f;k++){
					add=d[1][k][i][j];
					//printf("a %d %d %d %d\n",i,j,k,add);
					for(l=1;l<=tim;l++){
						if(add>d[l][k][i][j]){
							 add=d[l][k][i][j];
							// printf(" add  %d %d %d\n",k,l,add);
						 }
					}						
					tot+=add;
				}
				if(tot<ans){
					ans=tot; markx=i; marky=j;
				}
			}
		}
		
		if(ans>=inf) printf("Case #%d: Impossible.\n",t++);
		else printf("Case #%d: Selected city (%d,%d) with minimum cost %lld.\n",t++,markx-1,marky-1,ans);	
				
		
	}
	
	return 0;
}

void dij(node s,int c){
	
	int i,j,k,l;
	node temp,temp1;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=tim;k++){
				d[k][c][i][j]=inf;
			}
		}
	}
	
	i=s.x; j=s.y; 
	s.lev=1;
	d[1][c][i][j]=0; 
	s.cost=0;
	pq.push(s);
	
	while(!pq.empty()){
		
		temp=pq.top(); pq.pop();
		i=temp.x; j=temp.y;
		
		if(temp.lev==tim) continue;
		k=i-1; l=j;
		
		/*
		if(k>0&&l>0&&k<=n&&l<=n&&d[temp.lev+1][c][k][l]>temp.cost+mat[k][l]){
			d[temp.lev+1][c][k][l]=temp.cost+mat[k][l];
			temp1.lev=temp.lev+1;
			temp1.cost=d[temp.lev+1][c][k][l]; 
			
		}
		*/
		if(valid) {
			d[temp.lev+1][c][k][l]=temp.cost+mat[i][j];
         	temp1.lev=temp.lev+1;
			temp1.cost=d[temp.lev+1][c][k][l];
			temp1.x=k; temp1.y=l;
			pq.push(temp1); 
		}
		
		k=i+1; l=j;
		if(valid){
			d[temp.lev+1][c][k][l]=temp.cost+mat[i][j];
         	temp1.lev=temp.lev+1;
			temp1.cost=d[temp.lev+1][c][k][l];
			temp1.x=k; temp1.y=l;
			pq.push(temp1); 
		}
		
		k=i;l=j-1;
		
		if(valid){
			d[temp.lev+1][c][k][l]=temp.cost+mat[i][j];
         	temp1.lev=temp.lev+1;
			temp1.cost=d[temp.lev+1][c][k][l];
			temp1.x=k; temp1.y=l;
			pq.push(temp1); 
		}
		
		k=i;l=j+1;
		
		if(valid){
			
			d[temp.lev+1][c][k][l]=temp.cost+mat[i][j];
		   	temp1.lev=temp.lev+1;
			temp1.cost=d[temp.lev+1][c][k][l];
		
		//	printf("k-%d %d %d\n",k,l,temp1.cost);
			
			temp1.x=k; temp1.y=l;
			pq.push(temp1); 
		
		}
		
						
		
	}
	
	/*
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=tim;k++){
				printf("%d %d %d %d %d\n",i,j,k,c,d[k][c][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	*/
	/*
	for(k=1;k<=tim;k++){
		printf("c - %d \n",d[k][c][1][4]);
	}
	printf("\n");
	*/
 }
