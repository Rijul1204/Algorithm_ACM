#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 50000
#define ii long long int
#define inf 1<<29

struct node{
	int x,y,w;
};

int m,n,q;
node nodes[maxm+10];
int ts1();
int ts2(int x);
ii f(int x,int y);


int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d %d",&m,&n,&q);

		for(i=1;i<=q;i++){
			scanf("%d %d %d",&nodes[i].x,&nodes[i].y,&nodes[i].w);
		}
		int ansx=ts1();
		int ansy=ts2(ansx);
		
		printf("Case %d: %d %d\n",t++,ansx,ansy);

	}

	return 0;
}

int ts1(){

	int h,g,k,l;
	ii i,j;
	int min=1;
	int max=m;
	ii chck=-1;
	int prev=1;
	int c=33;

	while(c--){
		
		g=(2*min+max)/3;
		h=(min+2*max)/3;

		//k=ts2(g); l=ts2(h);
		i=f(g,1); j=f(h,1);
		if(i<j){
			max=h-1;
			if(chck==-1){
				chck=i;
				prev=g;
				continue;
			}
			if(chck>i){
				chck=i;
				prev=g;
				continue;			
			}
		}
		else{
			min=g+1;			
			if(chck==-1){
				chck=j;
				prev=h;
				continue;
			}
			if(chck>j){
				chck=j;
				prev=h;
				continue;			
			}
		}
	}
	return prev;
}

int ts2(int x){
	
	int h,g;
	ii i,j;
	int min=1;
	int max=n;
	int c=33;
	ii chck=-1;
	int prev=1;
	while(c--){

		g=(2*min+max)/3;
		h=(min+2*max)/3;

		i=f(x,g); j=f(x,h);
		
		if(i<j){
			max=h-1;
			
			if(chck==-1){
				chck=i;
				prev=g;
				continue;
			}
			if(chck>i){
				chck=i;
				prev=g;
				continue;			
			}
		}
		else{
			min=g+1;
			if(chck==-1){
				chck=j;
				prev=h;
				continue;
			}
			if(chck>j){
				chck=j;
				prev=h;
				continue;			
			}
		}
	}

	return prev; 
}

ii f(int x,int y){

	ii ret=0;
	int i,k,l;

	for(i=1;i<=q;i++){
		k=nodes[i].x-x; 
		if(k<0) k*=-1;
		l=nodes[i].y-y;
		if(l<0) l*=-1;
		ret+=((k+l)*nodes[i].w);
	}

	return ret;
}