#include<stdio.h>
#include<math.h>
//#include<algorithm>
//using namespace std;

typedef struct{
	int x;
	int y;
}nodes;

nodes node[1500];
double a[1200][1200];

void set(int n);
void minimax(int n);
double max(double a,double b);
double min(double a,double b);


int main(){

	int i,j,n,test=1;
	double temp1,temp2,mini,maxi;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n) && n){

		set(n);

		for(i=1;i<=n;i++){
			scanf("%d %d",&node[i].x,&node[i].y);
			for(j=1;j<i;j++){
				temp1= ((node[j].x-node[i].x)*(node[j].x-node[i].x))+((node[j].y-node[i].y)*(node[j].y-node[i].y));
			    temp1=sqrt(temp1);
                a[i][j]=a[j][i]=temp1;
			}		
 			
		}

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
	//			printf("%15.3lf",a[i][j]);				
			}
	//		printf("\n"); 			
		}

	//	printf("\n\n\n");

		minimax(n);

		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",test++,a[1][2]);

	}

	return 0;
}

void minimax(int n){

	int i,j,k;

	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				a[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
			}
		}
	}

}

double min(double a,double b){
	if(a<b) return a;
	else return b;
}


void set(int n){

	int i,j;

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			a[i][j]=0;
		}
	}
}


double max(double a,double b){
	if(a>b) return a;
	else return b;
}

			
			
			
			



			

		
