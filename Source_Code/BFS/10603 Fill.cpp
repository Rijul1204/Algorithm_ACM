#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define inf 123456789

struct node{
	int a1;
	int b1;
	int c1;
	int d;
};

int d[1000],a,b,c;
int col[210][210][210];
queue<node>q;
void bfs(node s);

int main(){

	int i,j,k,l,test,dest;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		col[1][0][0]=col[0][0][0]=1;
		memset(col,0,sizeof(col));
		
		for(i=0;i<=208;i++){
			d[i]=inf;
		}

		scanf("%d %d %d %d",&a,&b,&c,&dest);
		node temp;
		temp.a1=0;
		temp.b1=0;
		temp.c1=c;
		temp.d=0;
		bfs(temp);
		if(d[dest]!=inf) printf("%d %d\n",d[dest],dest);
		else{
			for(i=dest-1;i>=0;i--){
				if(d[i]!=inf){
					printf("%d %d\n",d[i],i);
					break;
				}
			}
		}
	}


	return 0;
}

void bfs(node s){
	
	d[s.c1]=0;
	col[0][0][c]=1;
	int i,j,k,l,num,i1,j1,k1,l1;
	node temp,temp1;	
	q.push(s);

	while(!q.empty()){
		temp=q.front();q.pop();
		i=temp.a1; j=temp.b1; k=temp.c1;
		num=temp.d;
		
		
		//1st glass............
		if(i<a){
			//2nd glass to 1st glass...........
			if(i+j<=a&&j!=0){
				i1=i+j;
				j1=0;
				k1=k;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+j;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
			}
			else if(i+j>a){
				i1=a;
				j1=i+j-a;
				k1=k;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+j-j1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
				
			}
			//3rd glass to  1st  glass...........................
			if(i+k<=a&&k!=0){
				i1=i+k;
				k1=0;
				j1=j;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+k-k1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
				
			}
			else if(i+k>a){
				i1=a;
				k1=i+k-a;
				j1=j;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+k-k1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
			}

		}

		// 2nd  glass.......................
		if(j<b){
			//1st glass to 2nd glass...........
			if(i+j<=b&&i!=0){
				j1=i+j;
				i1=0;
				k1=k;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+i-i1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
			}
			else if(i+j>b){
				j1=b;
				i1=j+i-b;
				k1=k;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+i-i1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
				
			}
			//3rd glass to  2nd  glass...........................
			if(j+k<=b&&k!=0){
				j1=k+j;
				k1=0;
				i1=i;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+k-k1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
				
			}
			else if(j+k>b){
				i1=i;
				k1=j+k-b;
				j1=b;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+k-k1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
			}

		}
		// 3rd  glass.............
		if(k<c){
			//1st glass to 3rd glass...........
			if(i+k<=c&&i!=0){
				k1=i+k;
				i1=0;
				j1=j;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+i-i1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
			}
			else if(i+k>c){
				j1=j;
				i1=k+i-c;
				k1=c;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+i-i1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
				
			}			

			//2nd glass to 3rd glass...........
			if(k+j<=c&&j!=0){
				i1=i;
				j1=0;
				k1=k+j;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+j;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;
			}
			else if(k+j>c){
				i1=i;
				j1=k+j-c;
				k1=c;
				temp1.a1=i1; temp1.b1=j1; temp1.c1=k1; temp1.d=num+j-j1;
				if(d[i1]>temp1.d) d[i1]=temp1.d;
				if(d[j1]>temp1.d) d[j1]=temp1.d;
				if(d[k1]>temp1.d) d[k1]=temp1.d;
				if(col[i1][j1][k1]==0) q.push(temp1);
				col[i1][j1][k1]=1;				
			}

		}


	}



}