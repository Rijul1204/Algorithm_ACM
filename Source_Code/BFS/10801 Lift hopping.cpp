#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<queue>
using namespace std;

#define inf 123456789

struct node{
	int no;
	int floor;
	int dis;
};

int lift[10][500];
int tim[10],n;
int d[110];

queue<node>q;
node t;

void dij(int s);

int main(){

	int i,j,k,l,dist;
	char s[10000];

	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&k)==2){

		dist=k;

		for(i=1;i<=n;i++){
			for(j=0;j<=110;j++){
				lift[i][j]=0;				
			}
		}
		for(i=0;i<=100;i++) d[i]=inf;
	

		for(i=1;i<=n;i++){
			scanf("%d",&tim[i]);
		}
		gets(s);

		for(i=1;i<=n;i++){
			gets(s);
			for(j=0;s[j];j++){
				if(s[j]==' ') continue;
				else if(isdigit(s[j])){
					k=0; char temp[100];
					while(isdigit(s[j])){
						temp[k++]=s[j++];
					}
					temp[k]='\0';
					j--;
					int num=atoi(temp);
					lift[i][num]=1;
					//printf("%d  ",num);
				}
			}
			//printf("\n");
		}		
//		printf("\n");

		dij(0);
		if(d[dist]!=inf) printf("%d\n",d[dist]);
		else printf("IMPOSSIBLE\n");



	}


	return 0;
}

void dij(int s){

	node temp,temp1;
	int i,j,k,l,i1,j1,k1,l1;

	for(i=1;i<=n;i++){
		if(lift[i][s]==1){
			temp.no=i;
			temp.floor=s;
			temp.dis=0;
			q.push(temp);
		}
	}
	d[s]=0;

	while(!q.empty()){
		
		temp=q.front(); q.pop();
		
		 i=temp.no;
		 j=temp.floor;

		for(k=0;k<100;k++){
			l=k-j;
			if(l<0) l*=-1;
			if(d[k]>temp.dis+(tim[i]*l)&&lift[i][k]==1){
				d[k]=temp.dis+ (tim[i]*l);
				//temp1.no=i;
				//temp1.floor=k;
				//temp1.dis=d[k];
				for(i1=1;i1<=n;i1++){
					if(i1==i) continue;
					if(lift[i1][k]==1){
						temp1.no=i1;
						temp1.floor=k;
						temp1.dis=d[k]+60;
						q.push(temp1);
					}
				}
				//q.push(temp1);
			}
		}


	}	


}
