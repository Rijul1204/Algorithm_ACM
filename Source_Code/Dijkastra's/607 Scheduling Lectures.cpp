#include<stdio.h>
#include<queue>
using namespace std;

#define maxm 2000
#define inf 1<<29

struct node{
	int rem;
	int no;
	int DI;
	int tot;
};


bool operator<(const node &a,const node &b){
	if(a.tot==b.tot) return a.DI>b.DI;
	return a.tot>b.tot;
}

node lect[maxm][600];
node ans;
priority_queue<node>q;
//queue<node>q;

int l,c,n;
int a[maxm];
void bfs(node s);


int main(){
	
	int i,j,k,t=1;
	
  //  freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){
		if(!n) break;
		
		scanf("%d %d",&l,&c);
		
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		
		for(i=1;i<=n;i++){
			for(j=0;j<=l;j++){
				lect[i][j].DI=lect[i][j].tot=inf;
			}
		}
		
		node temp;
		
		temp.DI=0; temp.no=1; temp.rem=l; temp.tot=0;
		bfs(temp);
		
		if(t>1) printf("\n");
		printf("Case %d:\n",t++);
        printf("Minimum number of lectures: %d\nTotal dissatisfaction index: %d\n",ans.tot,ans.DI);

		
		
		
	}	
	
	return 0;
}

void bfs(node s){
	
	int i,j,k;
	node temp,temp1;
    s.rem-=a[1]; s.no=1; s.tot=1;
	ans.tot=inf; ans.DI=inf;
	lect[1][s.rem].DI=0; lect[1][s.rem].tot=1;
	q.push(s);
	
	while(!q.empty()){
		
		//temp=q.front();
		temp=q.top();
		q.pop();
		
		if(temp.no==n){
			if(temp.rem==0) temp.DI=temp.DI;
			else if(temp.rem<=10) temp.DI=temp.DI-c;
			else temp.DI=temp.DI+(temp.rem-10)*(temp.rem-10);
			//printf("%d %d\n",temp.tot,temp.DI);
			if(ans.tot>temp.tot){
				ans=temp;
			}
			else if(ans.tot==temp.tot){
				if(ans.DI>temp.DI) ans=temp;
			}
			continue;
		}
		i=temp.no;
		
		//continue..............
		if(temp.rem>=a[i+1]){
			temp1.rem=temp.rem-a[i+1];
			temp1.no=i+1;
			temp1.DI=temp.DI; temp1.tot=temp.tot;
			if(lect[temp1.no][temp1.rem].tot>temp1.tot){
				lect[temp1.no][temp1.rem]=temp1;
				q.push(temp1);
			}
			else if(lect[temp1.no][temp1.rem].tot==temp1.tot){
				if(lect[temp1.no][temp1.rem].DI>temp1.DI){
					lect[temp1.no][temp1.rem]=temp1;
     				q.push(temp1);
				}
			}
		}
		
		temp1.no=i+1; temp1.tot=temp.tot+1; 
		if(temp.rem==0) temp1.DI=temp.DI;
		else if(temp.rem<=10) temp1.DI=temp.DI-c;
		else temp1.DI=temp.DI+(temp.rem-10)*(temp.rem-10);
		
		temp1.rem=l-a[i+1];

		    if(lect[temp1.no][temp1.rem].tot>temp1.tot){
				lect[temp1.no][temp1.rem]=temp1;
				q.push(temp1);
			}
			else if(lect[temp1.no][temp1.rem].tot==temp1.tot){
				if(lect[temp1.no][temp1.rem].DI>temp1.DI){
					lect[temp1.no][temp1.rem]=temp1;
     				q.push(temp1);
				}
			}
	
		
	//	q.push(temp1);
		
		
	}
	
	
	
}